Attribute VB_Name = "Sheet5"
Attribute VB_Base = "0{00020820-0000-0000-C000-000000000046}"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = True
Attribute VB_TemplateDerived = False
Attribute VB_Customizable = True
Attribute VB_Control = "Pfsplot1, 1078, 0, PFSPLOTLib, Pfsplot"
Attribute VB_Control = "cmdGoBackToWelcomePage, 1055, 1, MSForms, CommandButton"
Attribute VB_Control = "cmdUseDefaultValues, 1049, 2, MSForms, CommandButton"
Attribute VB_Control = "Label13, 1048, 3, MSForms, Label"
Attribute VB_Control = "Label12, 1047, 4, MSForms, Label"
Attribute VB_Control = "Label11, 1046, 5, MSForms, Label"
Attribute VB_Control = "Label10, 1045, 6, MSForms, Label"
Attribute VB_Control = "Label9, 1044, 7, MSForms, Label"
Attribute VB_Control = "txtC2, 1043, 8, MSForms, TextBox"
Attribute VB_Control = "txtC4, 1042, 9, MSForms, TextBox"
Attribute VB_Control = "txtC1, 1041, 10, MSForms, TextBox"
Attribute VB_Control = "txtC3, 1040, 11, MSForms, TextBox"
Attribute VB_Control = "Label8, 1039, 12, MSForms, Label"
Attribute VB_Control = "txtC5, 1038, 13, MSForms, TextBox"
Attribute VB_Control = "Label7, 1037, 14, MSForms, Label"
Attribute VB_Control = "Label6, 1036, 15, MSForms, Label"
Attribute VB_Control = "txtC7, 1035, 16, MSForms, TextBox"
Attribute VB_Control = "lblVeryLow, 1034, 17, MSForms, Label"
Attribute VB_Control = "lblLow, 1033, 18, MSForms, Label"
Attribute VB_Control = "lblMedium, 1032, 19, MSForms, Label"
Attribute VB_Control = "lblHigh, 1031, 20, MSForms, Label"
Attribute VB_Control = "lblVeryHigh, 1030, 21, MSForms, Label"
Attribute VB_Control = "txtC8, 1029, 22, MSForms, TextBox"
Attribute VB_Control = "txtC6, 1028, 23, MSForms, TextBox"
Attribute VB_Control = "cmdClear, 1027, 24, MSForms, CommandButton"
Attribute VB_Control = "cmdDQPD, 1026, 25, MSForms, CommandButton"
Private n_Click2 As Integer


Private Sub cmdUseDefaultValues_Click()
Dim x As Double

txtC1.Text = "0.1"
txtC2.Text = "0.1"
txtC3.Text = "1"
txtC4.Text = "1"
txtC5.Text = "10"
txtC6.Text = "10"
txtC7.Text = "100"
txtC8.Text = "100"

End Sub

Private Sub cmdClear_Click()
On Error GoTo errorhandler
    With Pfsplot1
        .PlotType = 2
        .GridType = 3
         .Clear
         
         n_Click2 = 0
         
        .SetLabel 0, "Solvent3 Fractions"
        .SetLabel 1, "Solvent1 Fractions"
        .SetLabel 2, "Solvent2 Fractions"
        .AddText "Solvent3", 1#, 1.65, 0, 0, 0, 0, 0
        .AddText "Solvent2", -0.5, 1.65, 0, 0, 0, 0, 0
        .AddText "Solvent1", 0.42, -0.2, 0, 0, 0, 0, 0
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

Private Sub cmdDQPD_Click()

Dim n_rows As Integer
Dim n_columns As Integer
' Const n_ranges As Integer = 5
Dim a(400, 5) As Double
Dim a1(400, 5) As Double
Dim a2(400, 5) As Double
Dim a3(400, 5) As Double
Dim a4(400, 5) As Double
Dim a5(400, 5) As Double
Dim n1 As Integer
Dim n2 As Integer
Dim n3 As Integer
Dim n4 As Integer
Dim n5 As Integer
Dim n_areas As Integer
Dim i, j, k, l As Integer

On Error GoTo errorhandler

If crctslct() = False Then Exit Sub
If crctrange() = False Then Exit Sub

n_Click2 = n_Click2 + 1

For i = 1 To 400
    For j = 1 To 5
        a(i, j) = 0
        a1(i, j) = 0
        a2(i, j) = 0
        a3(i, j) = 0
        a4(i, j) = 0
        a5(i, j) = 0
    Next
Next




n1 = 0
n2 = 0
n3 = 0
n4 = 0
n5 = 0
n_rows = 0
l = 0

n_areas = Selection.Areas.Count

 
With Pfsplot1

    .SetLabel 0, "Solvent3 Fractions"
    .SetLabel 1, "Solvent1 Fractions"
    .SetLabel 2, "Solvent2 Fractions"
    .nxvariables = 400                      'For one-click draw, it is n_ranges(5)
    .nvariables = 400                       'It should be big enough if multi-click draw is allowed
    
    For i = 1 To n_areas
        n_rows = n_rows + Selection.Areas.Item(i).Rows.Count
    Next
    
'  n_columns = Selection.Columns.Count

    For k = 1 To n_areas
        For i = 1 To Selection.Areas.Item(k).Rows.Count
            For j = 1 To 3
                a(l + i, j) = Selection.Areas.Item(k).Rows(i).Cells(j).Value
            Next j
            a(l + i, 4) = 1 - a(l + i, 1) - a(l + i, 2) - a(l + i, 3)
            a(l + i, 5) = a(l + i, 4) * 100 / (1 - a(l + i, 4))
        Next i
        l = l + Selection.Areas.Item(k).Rows.Count
    Next k
    
    For i = 1 To n_rows
        If (a(i, 5) * 10) < CDbl(txtC1.Text) Then
            n1 = n1 + 1
            a1(n1, 1) = a(i, 1)
            a1(n1, 2) = a(i, 2)
            a1(n1, 3) = a(i, 3)
            a1(n1, 4) = a(i, 4)
        ElseIf (a(i, 5) * 10) >= CDbl(txtC2.Text) And (a(i, 5) * 10) < CDbl(txtC3.Text) Then
            n2 = n2 + 1
            a2(n2, 1) = a(i, 1)
            a2(n2, 2) = a(i, 2)
            a2(n2, 3) = a(i, 3)
            a2(n2, 4) = a(i, 4)
        ElseIf (a(i, 5) * 10) >= CDbl(txtC4.Text) And (a(i, 5) * 10) < CDbl(txtC5.Text) Then
            n3 = n3 + 1
            a3(n3, 1) = a(i, 1)
            a3(n3, 2) = a(i, 2)
            a3(n3, 3) = a(i, 3)
            a3(n3, 4) = a(i, 4)
        ElseIf (a(i, 5) * 10) >= CDbl(txtC6.Text) And (a(i, 5) * 10) < CDbl(txtC7.Text) Then
            n4 = n4 + 1
            a4(n4, 1) = a(i, 1)
            a4(n4, 2) = a(i, 2)
            a4(n4, 3) = a(i, 3)
            a4(n4, 4) = a(i, 4)
        ElseIf (a(i, 5) * 10) > CDbl(txtC8.Text) Then
            n5 = n5 + 1
            a5(n5, 1) = a(i, 1)
            a5(n5, 2) = a(i, 2)
            a5(n5, 3) = a(i, 3)
            a5(n5, 4) = a(i, 4)
        End If
        
    Next i
        
    

        For i = 1 To n1
            .SetXData (n_Click2 - 1) * 5 + 1, (i - 1), a1(i, 3) / (a1(i, 1) + a1(i, 2) + a1(i, 3))
            .SetData (n_Click2 - 1) * 5 + 1, (i - 1), a1(i, 1) / (a1(i, 1) + a1(i, 2) + a1(i, 3))
   '         .Redraw
        Next i
    
        For i = 1 To n2
            .SetXData (n_Click2 - 1) * 5 + 2, (i - 1), a2(i, 3) / (a2(i, 1) + a2(i, 2) + a2(i, 3))
            .SetData (n_Click2 - 1) * 5 + 2, (i - 1), a2(i, 1) / (a2(i, 1) + a2(i, 2) + a2(i, 3))
   '        .Redraw
        Next i
        
        For i = 1 To n3
            .SetXData (n_Click2 - 1) * 5 + 3, (i - 1), a3(i, 3) / (a3(i, 1) + a3(i, 2) + a3(i, 3))
            .SetData (n_Click2 - 1) * 5 + 3, (i - 1), a3(i, 1) / (a3(i, 1) + a3(i, 2) + a3(i, 3))
  '          .Redraw
        Next i
        
        For i = 1 To n4
            .SetXData (n_Click2 - 1) * 5 + 4, (i - 1), a4(i, 3) / (a4(i, 1) + a4(i, 2) + a4(i, 3))
            .SetData (n_Click2 - 1) * 5 + 4, (i - 1), a4(i, 1) / (a4(i, 1) + a4(i, 2) + a4(i, 3))
  '         .Redraw
        Next i
        
        For i = 1 To n5
            .SetXData (n_Click2 - 1) * 5 + 5, (i - 1), a5(i, 3) / (a5(i, 1) + a5(i, 2) + a5(i, 3))
            .SetData (n_Click2 - 1) * 5 + 5, (i - 1), a5(i, 1) / (a5(i, 1) + a5(i, 2) + a5(i, 3))
  '         .Redraw
        Next i
        
        .SetAttribute (n_Click2 - 1) * 5, -1, 6, 0
        .SetAttribute (n_Click2 - 1) * 5 + 1, -1, 6, 7
        .SetAttribute (n_Click2 - 1) * 5 + 2, -1, 6, 10
        .SetAttribute (n_Click2 - 1) * 5 + 3, -1, 6, 3
        .SetAttribute (n_Click2 - 1) * 5 + 4, -1, 6, 1
   '        .Redraw
        
    
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

Function crctslct() As Boolean
Dim ncolumn As Integer
    
    crctslct = True

'    If InStr(Selection.Address, ",") > 1 Then
'        MsgBox "It's not a continuous field, please select a continuous field¡£"
'        crctslct = False
'        Exit Function
'    End If
    
    ncolumn = Selection.Columns.Count
    
    
    If ncolumn <> 3 Then
        MsgBox ("Please select 3 columns of data for solvents' mass fractions.")
        crctslct = False
        Exit Function
    End If
    
End Function
Function crctrange() As Boolean

crctrange = True

If CDbl(txtC3.Text) <= CDbl(txtC2.Text) Then
    MsgBox "Error! please check the 'Low' solubility range definition."
    crctrange = False
    Exit Function
End If
  
If CDbl(txtC5.Text) <= CDbl(txtC4.Text) Then
    MsgBox "Error! please check the 'Medium' solubility range definition."
    crctrange = False
    Exit Function
End If
      
If CDbl(txtC7.Text) <= CDbl(txtC6.Text) Then
    MsgBox "Error! please check the 'High' solubility range definition."
    crctrange = False
    Exit Function
End If


End Function







Private Sub txtC1_Change()
txtC2.Text = txtC1.Text
End Sub

Private Sub txtC2_Change()
txtC1.Text = txtC2.Text
End Sub

Private Sub txtC3_Change()
txtC4.Text = txtC3.Text
End Sub

Private Sub txtC5_Change()
txtC6.Text = txtC5.Text
End Sub

Private Sub txtC4_Change()
txtC3.Text = txtC4.Text
End Sub

Private Sub txtC6_Change()
txtC5.Text = txtC6.Text
End Sub

Private Sub txtC7_Change()
txtC8.Text = txtC7.Text
End Sub

Private Sub txtC8_Change()
txtC7.Text = txtC8.Text
End Sub

Private Sub worksheet_change(ByVal Target As Range)
If ActiveSheet.CodeName = "Sheet5" Then
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
'    Sheet5.EnableCalculation = False
'End Sub
Private Sub cmdGoBackToWelcomePage_Click()
    ActiveSheet.Visible = xlSheetVeryHidden
    Sheet14.Visible = xlSheetVisible
    Sheet2.Visible = xlSheetVeryHidden
End Sub
