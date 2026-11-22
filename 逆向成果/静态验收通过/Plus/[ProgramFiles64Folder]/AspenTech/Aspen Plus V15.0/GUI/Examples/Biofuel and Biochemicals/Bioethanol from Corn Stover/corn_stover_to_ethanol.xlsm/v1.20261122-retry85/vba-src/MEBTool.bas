Attribute VB_Name = "MEBTool"
' Version 2.0 - Jan. 31, 2006 (TJE)
'   1) Modified code so that the "Set-Up" sheet defines which sheets to run the MEB tool
'   2) Updated MEBAspenGUI and MEBAspenSummary modules to handle hierarchy

Option Explicit

Dim myFile As String
Dim Munits As String
Dim Hunits As String

Sub Run_MEBTool()
    
' This routine drives the MEB tool program

    Dim i As Integer

    InitializeCalculations
    For i = 1 To Worksheets("Set-Up").Range("B12").CurrentRegion.Rows.Count
        ExtractMEB Worksheets("Set-Up").Range("B12").Offset(i - 1, 0).Value
    Next i
    CleanUp

End Sub

Private Sub InitializeCalculations()

' This routine reads the configuration data in the Excel set-up sheet,
' and sets up the connection to the simulator

    Dim myRangeAnchor As Range
    Dim i As Integer
    
    myFile = Worksheets("Set-Up").Range("B1").Value
    Munits = Worksheets("Set-Up").Range("B3").Value
    Hunits = Worksheets("Set-Up").Range("B4").Value
    
    InitializeSimulatorInterface myFile, Munits, Hunits

End Sub

Sub ExtractMEB(mySheetName As String)
   
' This routine processes a single MEB sheet in the work book.
    
    Dim mySheet As Worksheet
    Dim myInAnchor As Range
    Dim myOutAnchor As Range
    Dim myClosureAnchor As Range
    Dim myAnchor As Range
    Dim i As Integer
    Dim nEntries As Integer
    Dim MassIn As Double
    Dim MassOut As Double
    Dim HIn As Double
    Dim HOut As Double
    Dim StreamType As String
    Dim Mass As Double
    Dim H As Double
    
    Const EPS = 0.000001
    
' Set up locations and stamp the sheet with the simulation file name, date/time and units

    Set mySheet = Worksheets(mySheetName)
    Set myInAnchor = mySheet.Range("B11")
    Set myOutAnchor = mySheet.Range("I11")
    Set myClosureAnchor = mySheet.Range("R11")
    
    mySheet.Range("K3").Value = myFile
    mySheet.Range("J4").Value = Date & " " & Time
    
    myInAnchor.Offset(-2, 2).Value = Munits
    myInAnchor.Offset(-2, 4).Value = Hunits
    myOutAnchor.Offset(-2, 2).Value = Munits
    myOutAnchor.Offset(-2, 4).Value = Hunits

' Now clear previous entries
    
    For i = 1 To myInAnchor.Offset(0, 2).CurrentRegion.Rows.Count
        myInAnchor.Offset(i - 1, 1).Value = ""
        myInAnchor.Offset(i - 1, 2).Value = ""
        myInAnchor.Offset(i - 1, 2).Borders(xlEdgeTop).LineStyle = xlNone
        myInAnchor.Offset(i - 1, 2).Borders(xlEdgeBottom).LineStyle = xlNone
        myInAnchor.Offset(i - 1, 4).Value = ""
        myInAnchor.Offset(i - 1, 4).Borders(xlEdgeTop).LineStyle = xlNone
        myInAnchor.Offset(i - 1, 4).Borders(xlEdgeBottom).LineStyle = xlNone
    Next i
    
    For i = 1 To myOutAnchor.Offset(0, 2).CurrentRegion.Rows.Count
        myOutAnchor.Offset(i - 1, 1).Value = ""
        myOutAnchor.Offset(i - 1, 2).Value = ""
        myOutAnchor.Offset(i - 1, 2).Borders(xlEdgeTop).LineStyle = xlNone
        myOutAnchor.Offset(i - 1, 2).Borders(xlEdgeBottom).LineStyle = xlNone
        myOutAnchor.Offset(i - 1, 4).Value = ""
        myOutAnchor.Offset(i - 1, 4).Borders(xlEdgeTop).LineStyle = xlNone
        myOutAnchor.Offset(i - 1, 4).Borders(xlEdgeBottom).LineStyle = xlNone
    Next i
    
    myClosureAnchor.Value = ""
    myClosureAnchor.Offset(0, 2).Value = ""
    myClosureAnchor.Offset(1, 0).Value = ""
    myClosureAnchor.Offset(1, 2).Value = ""

' Extract the in's

    MassIn = 0
    HIn = 0
    
    nEntries = 0
    Do While myInAnchor.Offset(nEntries, 0).Value <> ""
        nEntries = nEntries + 1
    Loop
    
    For i = 1 To nEntries
    
        Application.StatusBar = "Extracting " & mySheetName & " Stream: " & myInAnchor.Offset(i - 1, 0).Value
        
        ExtractStream myInAnchor.Offset(i - 1, 0).Value, Munits, Hunits, StreamType, Mass, H
            
        If StreamType = "Mass" Then
            MassIn = MassIn + Mass
            HIn = HIn + H
            myInAnchor.Offset(i - 1, 2).Value = Mass
            myInAnchor.Offset(i - 1, 4).Value = H
        ElseIf StreamType = "Energy" Then
            HIn = HIn + H
            myInAnchor.Offset(i - 1, 2).Value = "-"
            myInAnchor.Offset(i - 1, 4).Value = H
        End If
    
    Next i
    
    myInAnchor.Offset(nEntries, 1).Value = "Total"
    myInAnchor.Offset(nEntries, 1).HorizontalAlignment = xlRight
    
    myInAnchor.Offset(nEntries, 2).Value = MassIn
    With myInAnchor.Offset(nEntries, 2).Borders(xlEdgeTop)
        .LineStyle = xlContinuous
        .Weight = xlThin
        .ColorIndex = xlAutomatic
    End With
    
    myInAnchor.Offset(nEntries, 4).Value = HIn
    With myInAnchor.Offset(nEntries, 4).Borders(xlEdgeTop)
        .LineStyle = xlContinuous
        .Weight = xlThin
        .ColorIndex = xlAutomatic
    End With
    
' Extract the out's

    MassOut = 0
    HOut = 0
    
    nEntries = 0
    Do While myOutAnchor.Offset(nEntries, 0).Value <> ""
        nEntries = nEntries + 1
    Loop
    
    For i = 1 To nEntries
    
        Application.StatusBar = "Extracting " & mySheetName & " Stream: " & myOutAnchor.Offset(i - 1, 0).Value
    
        ExtractStream myOutAnchor.Offset(i - 1, 0).Value, Munits, Hunits, StreamType, Mass, H
            
        If StreamType = "Mass" Then
            MassOut = MassOut + Mass
            HOut = HOut + H
            myOutAnchor.Offset(i - 1, 2).Value = Mass
            myOutAnchor.Offset(i - 1, 4).Value = H
        ElseIf StreamType = "Energy" Then
            HOut = HOut + H
            myOutAnchor.Offset(i - 1, 2).Value = "-"
            myOutAnchor.Offset(i - 1, 4).Value = H
        End If
    
    Next i

    myOutAnchor.Offset(nEntries, 1).Value = "Total"
    myOutAnchor.Offset(nEntries, 1).HorizontalAlignment = xlRight

    myOutAnchor.Offset(nEntries, 2).Value = MassOut
    With myOutAnchor.Offset(nEntries, 2).Borders(xlEdgeTop)
        .LineStyle = xlContinuous
        .Weight = xlThin
        .ColorIndex = xlAutomatic
    End With
    
    myOutAnchor.Offset(nEntries, 4).Value = HOut
    With myOutAnchor.Offset(nEntries, 4).Borders(xlEdgeTop)
        .LineStyle = xlContinuous
        .Weight = xlThin
        .ColorIndex = xlAutomatic
    End With
    
' Fill out the closure entries


    myClosureAnchor.Value = MassOut - MassIn
    If Abs(MassIn) > EPS Then myClosureAnchor.Offset(0, 2).Value = (MassOut - MassIn) / MassIn
    myClosureAnchor.Offset(1, 0) = HOut - HIn
    If Abs(HIn) > EPS Then myClosureAnchor.Offset(1, 2) = (HOut - HIn) / HIn

End Sub

Private Sub CleanUp()

' This routine cleans up before ending the program

    CloseSimulatorInterface
    
End Sub

