Attribute VB_Name = "Module1"
Public Const aspenPropertiesAddInStr As String = "Aspen Properties"
Public gbAddinInstalled As Boolean
' The prog id for the current version of the addin
Public Const APAddinProgid = "APXLAddinLoader.Connect.V15.0"
Public app As AspenPropertiesExcelCalculator.PropertiesApp



''!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
'' Find out all the boundary points

'Private Sub Clear_Click()
'
'    With Sheet12.Pfsplot1
'
'    .SetAxisMode 1, 0, 2
'    .SetAxisMode 2, 0, 1
'    .SetAxisMode 2, 1, 1
'
'
'         .Clear
'
'
'
'         .SetLabel 0, Sheet12.Range("C5").Value & " Fraction" '"Solvent2 Fraction" '
'         .SetLabel 1, Sheet12.Range("D5").Value & " Fraction" '"Solvent3 Fraction"
'         .SetLabel 2, Sheet12.Range("b5").Value & " Fraction" '"Solvent1 Fraction"
'         .AddText Sheet12.Range("C5").Value, 1#, 1.65, 0, 0, 0, 0, 0
'         .AddText Sheet12.Range("B5").Value, -0.5, 1.65, 0, 0, 0, 0, 0
'         .AddText Sheet12.Range("D5").Value, 0.43, -0.2, 0, 0, 0, 0, 0
'
'
'
'
'    End With
'
'End Sub
'
''
'
'
'Private Sub DrawPoint_Click()
'Dim beta() As Double
'Dim X1(), X2(), X3() As Double
'Dim BPX1(), BPX2(), BPX3() As Double
'Dim i, j As Integer
'Dim NofBP As Integer
'
'
'With Sheet12
'
'       Dim NofGA, NofPA As Integer
'
'       NofGA = Range("GDensity").Value
'       NofPA = (NofGA + 2) * (NofGA + 1) / 2
'
'       ReDim beta(NofGA + 1, NofGA + 1) As Double
'       ReDim P(1 To NofPA + 1), BP(1 To NofPA), X1(NofGA, NofGA), X2(NofGA, NofGA), X3(NofGA, NofGA) As Double
'       ReDim BPX1(1 To NofPA), BPX2(1 To NofPA), BPX3(1 To NofPA)
'
'        NofBP = 0
'
'        For i = 0 To NofGA
'                Range("b17").Value = 1 / NofGA * i
'           For j = 0 To NofGA - i
'             If i <> NofGA Then
'                Range("c17").Value = (1 - 1 / NofGA * i) * 1 / (NofGA - i) * j
'             Else
'                Range("c17").Value = 0
'             End If
'                Range("d17").Value = 1 - Range("b17").Value - Range("c17").Value
'                Range("E17").Select
'                ActiveCell.Formula = "=TPFlash3($B$5:$D$5,B17:D17,$B$7,$B$6,""beta"",$f$2)"
''           ActiveCell.Formula = "=TPFlash3(B5:D5," & "B" & 16 + i & ":D" & 16 + i & ",$B$7,$B$6,""beta"")"
''           ActiveCell.Formula = "=TPFlash3({""WATER"",""BENZENE"",""ETHANOL""},B17:D17,$B$7,$B$6,""beta"")" ' Don't work.
'                beta(i, j) = Range("E17").Value
'
'           X1(i, j) = Range("b17").Value
'           X2(i, j) = Range("c17").Value
'           X3(i, j) = Range("d17").Value
'
'
'           Next j
'        Next i
'
'        For i = 0 To NofGA
'           For j = 1 To NofGA - i
'
'           If ((beta(i, j) <> 1 And beta(i, j - 1) = 1) Or (beta(i, j) <> 1 And beta(i, j + 1) = 1)) Then
'                NofBP = NofBP + 1
'                BPX1(NofBP) = X1(i, j)
'                BPX2(NofBP) = X2(i, j)
'                BPX3(NofBP) = X3(i, j)
'           End If
'
'           Next j
'        Next i
'
'
'
'
'
'
'        Range("F4").Value = ""
'
'
'    End With
'
'
'With Sheet12.Pfsplot1
'
'    .Clear
'    .SetLabel 0, Sheet12.Range("C5").Value & " Fraction"
'    .SetLabel 1, Sheet12.Range("D5").Value & " Fraction"
'    .SetLabel 2, Sheet12.Range("B5").Value & " Fraction"
'    .AddText Sheet12.Range("C5").Value, 1#, 1.65, 0, 0, 0, 0, 0
'    .AddText Sheet12.Range("B5").Value, -0.5, 1.65, 0, 0, 0, 0, 0
'    .AddText Sheet12.Range("D5").Value, 0.43, -0.2, 0, 0, 0, 0, 0
'    .nxvariables = NofBP
'    .nvariables = NofBP
'
'
'
'    For i = 1 To NofBP
'
'        .SetXData 1, (i - 1), BPX2(i)
'        .SetData 1, (i - 1), BPX3(i)
' '      .Redraw
'    Next i
'
'    .SetAttribute 0, -1, 6, 0
'
'End With
'
'
'
'End Sub
'
''Find out all the boundary points
''!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
''!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!






''Draw tie lines!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
''!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


Public Function CheckAddInInstalled() As Boolean
    Dim retVal As String
    Dim isLoaded As Boolean
    Dim mcolIdx As Integer
    
        On Error Resume Next
        isLoaded = False
        For Each addin In Application.COMAddIns
            If InStr(1, addin.progID, "APXLAddinLoader.Connect") = 1 And addin.Connect = True Then
                isLoaded = True
                Exit For
            End If
        Next
        
        ' Check whether Addin has been installed for Aspen Properties
        If isLoaded = False Then
            'retVal = "The Aspen Properties add-in is not enabled.  Please enable it using 'Aspen Excel Add-in Manager'."
            retVal = "The Aspen Properties add-in is not enabled"
            mcolIdx = 3
        Else
            retVal = "Aspen Properties Add-In enabled"
            mcolIdx = 1
        End If
        
        Application.Range("AddinInfo").Value = retVal
        Application.Range("AddinInfo").Font.ColorIndex = mcolIdx
        Application.Range("AddinInfo").Font.Bold = True
        
        If isLoaded = True Then
            Application.StatusBar = False
        Else
            Application.StatusBar = "Aspen Properties Add-In is not enabled."
        End If
        
              
        CheckAddInInstalled = isLoaded
        
    
End Function


Public Function CheckAddInInstalled1() As Boolean
    Dim retVal As String
    Dim isLoaded As Boolean
    Dim mcolIdx As Integer
    Dim addin As COMAddIn
    
        On Error Resume Next
        isLoaded = False
        
        For Each addin In Application.COMAddIns
            If addin.progID = APAddinProgid And addin.Connect = True Then
            
                isLoaded = True
                Exit For
                
            End If
        Next
        
        ' Check whether Addin has been installed for Aspen Properties
        If isLoaded = False Then
            'retVal = "The Aspen Properties add-in is not enabled.  Please enable it using 'Aspen Excel Add-in Manager'."
            retVal = "The Aspen Properties add-in is not enabled"
            mcolIdx = 3
        Else
            retVal = "Aspen Properties Add-In enabled"
            mcolIdx = 1
        End If
        
        Application.Range("AddinInfo").Value = retVal
        Application.Range("AddinInfo").Font.ColorIndex = mcolIdx
        Application.Range("AddinInfo").Font.Bold = True
        
        If isLoaded = True Then
            Application.StatusBar = False
        Else
            Application.StatusBar = "Aspen Properties Add-In is not enabled."
        End If
        
              
        CheckAddInInstalled1 = isLoaded
        
    
End Function



