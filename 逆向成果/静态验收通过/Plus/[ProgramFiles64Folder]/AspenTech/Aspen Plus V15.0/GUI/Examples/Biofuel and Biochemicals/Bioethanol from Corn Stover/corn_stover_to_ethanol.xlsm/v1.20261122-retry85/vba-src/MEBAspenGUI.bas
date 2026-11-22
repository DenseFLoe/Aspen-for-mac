Attribute VB_Name = "MEBAspenGUI"
' This module handles the interface with Aspen GUI.  Four routines are required for this interface:
'
' PickSimulationFileName( myFileNameRange as Range )
' InitializeSimulatorInterface( myFile as String, Munits as String, Hunits as String )
' ExtractStream( myStreamName as String, Munits as String, Hunits as String, StreamType as String, Mass as double, H as double )
' CloseSimulatorInterface()
'
' Version 2.0 - Jan. 31, 2006 (TJE)
'   1) Modified code to handle hierarchy and changed unit conversion procedure to speed-up execution
'
' Notes for possible improvements in future releases:
'   1)Try to use index or some other more intelligent method for finding columns for unit conversion
'   2)Look at set-up for the stream class to see if conventional is
'     chosen.  If so, then there isn't a $TOTAL stream and the ExtractStream routine fails...modify logic to
'     to handle this case

Option Explicit

Private Type AspenStreamInfo
    Node As IHNode
    FullName As String
End Type

Private ihAPSim As HappIP
Private Streams() As AspenStreamInfo
Private nStreams As Integer
Private nRowMassFlow As Integer
Private nRowEnthalpyFlow As Integer
Private nRowPower As Integer
Private iMassFlow As Integer
Private iEnthalpyFlow As Integer
Private iPower As Integer

Public Sub PickSimulationFileName(myFileNameRange As Range)

' This routine displays the standard Open dialog box with *.apw, *.bkp, and *.* as the available
' files for the user to pick

    Dim FileName As String
    Dim FileFilter As String
    Dim Title As String
    
    FileFilter = "Aspen Plus User Interface Files (*.apw; *.bkp; *.apwz),*.apwz; *.apw; *.bkp,All Files (*.*),*.*"
    Title = "Aspen Plus User Interface Files"
    
    FileName = Application.GetOpenFilename(FileFilter, 1, Title)
    If FileName <> "False" Then myFileNameRange.Value = FileName

End Sub

Public Sub InitializeSimulatorInterface(myFile As String, Munits As String, Hunits As String)

' This routine sets up the interface with the simulator

    Dim ihStreams As IHNode
    Dim ihStream As IHNode
    
    Dim BaseName As String

    Dim Found As Boolean
    Dim i As Integer

    Dim Msg As String
    Dim Title As String
    Dim style As Integer
    Dim reply As Integer

' Connect to Aspen GUI

    Application.StatusBar = "Connecting to Aspen GUI"
    On Error GoTo ErrorTrap
    Set ihAPSim = GetObject(myFile)
    ihAPSim.Visible = True

' Store the stream nodes in a modular level array and set-up unit conversions
' ...this cuts down on automation overhead and speeds-up the program

    nStreams = 0
    BaseName = ""
    
    FillStreams ihAPSim.Tree.Data, BaseName

' find MASS-FLOW in the Unit Table

    Found = False
    For i = 1 To ihAPSim.Tree.Elements("Unit Table").Elements.Count
        If ihAPSim.Tree.Elements("Unit Table").Elements.Label(0, i - 1) = "MASS-FLOW" Then
            Found = True
            nRowMassFlow = i
            Exit For
        End If
    Next i
    If Not Found Then
        Msg = "Could not find MASS-FLOW in Unit Table"
        style = vbOKOnly
        Title = "Data Extraction Error"
        reply = MsgBox(Msg, style, Title)
        CloseSimulatorInterface
        End
    End If

' find Munit in the MASS-FLOW entries

    Found = False
    For i = 1 To ihAPSim.Tree.Elements("Unit Table").Elements(nRowMassFlow - 1).Elements.Count
        If ihAPSim.Tree.Elements("Unit Table").Elements(nRowMassFlow - 1).Elements.Label(0, i - 1) = Munits Then
            Found = True
            iMassFlow = i
            Exit For
        End If
    Next i
    If Not Found Then
        Msg = "Could not convert enthalpy into units : " & Munits
        style = vbOKOnly
        Title = "Data Extraction Error"
        reply = MsgBox(Msg, style, Title)
        CloseSimulatorInterface
        End
    End If

' find ENTHALPY-FLO in the Unit Table

    Found = False
    For i = 1 To ihAPSim.Tree.Elements("Unit Table").Elements.Count
        If ihAPSim.Tree.Elements("Unit Table").Elements.Label(0, i - 1) = "ENTHALPY-FLO" Then
            Found = True
            nRowEnthalpyFlow = i
            Exit For
        End If
    Next i
    If Not Found Then
        Msg = "Could not find ENTHALPY-FLO in Unit Table"
        style = vbOKOnly
        Title = "Data Extraction Error"
        reply = MsgBox(Msg, style, Title)
        CloseSimulatorInterface
        End
    End If
    
' find Hunit in the ENTHALPY-FLO entries

    Found = False
    For i = 1 To ihAPSim.Tree.Elements("Unit Table").Elements(nRowEnthalpyFlow - 1).Elements.Count
            If ihAPSim.Tree.Elements("Unit Table").Elements(nRowEnthalpyFlow - 1).Elements.Label(0, i - 1) = Hunits Then
                Found = True
                iEnthalpyFlow = i
                Exit For
            End If
    Next i
    If Not Found Then
        Msg = "Could not convert enthalpy into units : " & Hunits
        style = vbOKOnly
        Title = "Data Extraction Error"
        reply = MsgBox(Msg, style, Title)
        CloseSimulatorInterface
        End
    End If
    
' find POWER in the Unit Table

    Found = False
    For i = 1 To ihAPSim.Tree.Elements("Unit Table").Elements.Count
        If ihAPSim.Tree.Elements("Unit Table").Elements.Label(0, i - 1) = "POWER" Then
            Found = True
            nRowPower = i
            Exit For
        End If
    Next i
    If Not Found Then
        Msg = "Could not find POWER in Unit Table"
        style = vbOKOnly
        Title = "Data Extraction Error"
        reply = MsgBox(Msg, style, Title)
        CloseSimulatorInterface
        End
    End If
    
' find Hunits in the POWER entries

    Found = False
    For i = 1 To ihAPSim.Tree.Elements("Unit Table").Elements(nRowPower - 1).Elements.Count
            If ihAPSim.Tree.Elements("Unit Table").Elements(nRowPower - 1).Elements.Label(0, i - 1) = Hunits Then
                Found = True
                iPower = i
                Exit For
            End If
    Next i
    If Not Found Then
        Msg = "Could not convert power into units : " & Hunits
        style = vbOKOnly
        Title = "Data Extraction Error"
        reply = MsgBox(Msg, style, Title)
        CloseSimulatorInterface
        End
    End If

    Application.StatusBar = False
    Exit Sub

ErrorTrap:
    Msg = "The following error occurred while loading Aspen GUI: " & Err.Description
    style = vbOKOnly
    Title = "Aspen Loading Error"
    reply = MsgBox(Msg, style, Title)
    CloseSimulatorInterface
    End

End Sub

Private Sub FillStreams(DataNode As IHNode, BaseName As String)

' This recursive routine searches through the tree structure for all of the
' the streams in each hierarchy level.  Once it finds a stream, it places the
' stream info in the Streams modular level array

    Dim ihStreamList As IHNode
    Dim ihBlockList As IHNode
    Dim ihStream As IHNode
    Dim ihBlock As IHNode
    
    Set ihStreamList = DataNode.Streams
    Set ihBlockList = DataNode.Blocks
            
' First do this hierarchy level

    For Each ihStream In ihStreamList.Elements
        nStreams = nStreams + 1
        ReDim Preserve Streams(1 To nStreams) As AspenStreamInfo
        Set Streams(nStreams).Node = ihStream
        Streams(nStreams).FullName = BaseName & ihStream.Name
    Next ihStream
    
' Now do each of the sub hierarchy levels

    For Each ihBlock In ihBlockList.Elements
        If ihBlock.AttributeValue(HAP_RECORDTYPE) = "Hierarchy" Or ihBlock.AttributeValue(HAP_RECORDTYPE) = "HIERARCHY" Then
            If BaseName = "" Then
                FillStreams ihBlock.Data, ihBlock.Name & "."
            Else
                FillStreams ihBlock.Data, BaseName & ihBlock.Name & "."
            End If
        End If
    Next ihBlock

End Sub
Public Sub ExtractStream(myStreamName As String, Munits As String, Hunits As String, StreamType As String, Mass As Double, H As Double)

' This routine extracts the temperature and enthalpy data from a stream

    Dim ihStream As IHNode
    Dim ihStreams As IHNode
    Dim ihMVar As IHNode
    Dim ihHVar As IHNode
    Dim ihPhase As IHNode
    Dim Found As Boolean
    Dim Treport As Double
    Dim TestVal As Double
    Dim nRow As Long
    Dim nCol As Long
    Dim i As Integer
    
    Dim Msg As String
    Dim Title As String
    Dim style As Integer
    Dim reply As Integer
    
' Get the right stream
    
    Found = False
    For i = 1 To nStreams
        If myStreamName = Streams(i).FullName Then
            Found = True
            Set ihStream = Streams(i).Node
            Exit For
        End If
    Next i
    
    If Not Found Then
        Msg = "Could not find stream: " & myStreamName
        style = vbOKOnly
        Title = "Data Extraction Error"
        reply = MsgBox(Msg, style, Title)
        CloseSimulatorInterface
        End
    End If

    Select Case ihStream.AttributeValue(HAP_RECORDTYPE)
        
        Case "MATERIAL"
            
            StreamType = "Mass"
            Set ihMVar = ihStream.Output.MASSFLMX
            Found = False
            For Each ihPhase In ihMVar.Elements
                If ihPhase.Name = "$TOTAL" And ihPhase.Value <> "" Then
                    Mass = ihPhase.ValueForUnit(nRowMassFlow, iMassFlow)
                    Found = True
                    Exit For
                End If
            Next ihPhase
        
            If Not Found Then
                Msg = "Could not find mass flow for stream: " & myStreamName
                style = vbOKOnly
                Title = "Data Extraction Error"
                reply = MsgBox(Msg, style, Title)
                CloseSimulatorInterface
                End
            End If
        
            Set ihHVar = ihStream.Output.HMX_FLOW
            Found = False
            For Each ihPhase In ihHVar.Elements
                If ihPhase.Name = "$TOTAL" And ihPhase.Value <> "" Then
                    H = ihPhase.ValueForUnit(nRowEnthalpyFlow, iEnthalpyFlow)
                    Found = True
                    Exit For
                End If
            Next ihPhase
            
            If Not Found Then
                Msg = "Could not find enthalpy for stream: " & myStreamName
                style = vbOKOnly
                Title = "Data Extraction Error"
                reply = MsgBox(Msg, style, Title)
                CloseSimulatorInterface
                End
            End If
        
        Case "HEAT"
        
            StreamType = "Energy"
            Set ihHVar = ihStream.Output.QCALC
            If ihHVar.Value <> "" Then
                H = ihHVar.ValueForUnit(nRowEnthalpyFlow, iEnthalpyFlow)
            Else
                Msg = "Could not find enthalpy for stream: " & myStreamName
                style = vbOKOnly
                Title = "Data Extraction Error"
                reply = MsgBox(Msg, style, Title)
                CloseSimulatorInterface
                End
            End If

        Case "WORK"
        
            StreamType = "Energy"
            Set ihHVar = ihStream.Output.POWER_OUT
            If ihHVar.Value <> "" Then
                H = ihHVar.ValueForUnit(nRowPower, iPower)
            Else
                Msg = "Could not find enthalpy for stream: " & myStreamName
                style = vbOKOnly
                Title = "Data Extraction Error"
                reply = MsgBox(Msg, style, Title)
                CloseSimulatorInterface
                End
            End If
            
        Case Else
        
            Msg = myStreamName & "is of unexpected type: " & ihStream.AttributeValue(HAP_RECORDTYPE)
            style = vbOKOnly
            Title = "Data Extraction Error"
            reply = MsgBox(Msg, style, Title)
            CloseSimulatorInterface
            End
        
    End Select

    
End Sub

Public Sub CloseSimulatorInterface(Optional Idummy As Integer)
        
' This routine updates the status bar shuts down the interface with the simulator.  The argument Idummy is not used...it just keeps
' this routine from being listed as one of the macros that can be ran by Excel

    Set ihAPSim = Nothing
    Application.StatusBar = False
    
End Sub


