Attribute VB_Name = "Connectivity"


Option Explicit
Sub Main()
Attribute Main.VB_ProcData.VB_Invoke_Func = " \n14"
Call ConnectivityExample(OpenSimulation())
End Sub



Sub ConnectivityExample(ihAPsim As IHapp)
Attribute ConnectivityExample.VB_ProcData.VB_Invoke_Func = " \n14"
' This example displays a table showing flowsheet connectivity
Dim ihStreamList As IHNode
Dim ihBlockList As IHNode
Dim ihDestBlock As IHNode
Dim ihSourceBlock As IHNode
Dim ihStream As IHNode
Dim strHeading As String
Dim strTable As String
Dim strDestBlock As String
Dim strDestPort As String
Dim strSourceBlock As String
Dim strSourcePort As String
Dim strStreamName As String
Dim strStreamType As String

On Error GoTo ErrorHandler
Set ihStreamList = ihAPsim.Tree.Data.Streams
Set ihBlockList = ihAPsim.Tree.Data.Blocks

strHeading = "Stream" & Chr(9) & "From" _
        & Chr(9) & Chr(9) & Chr(9) & "To" & Chr(13)

For Each ihStream In ihStreamList.Elements
strStreamName = ihStream.Name
strStreamType = ihStream.AttributeValue(HAP_RECORDTYPE)
' get the destination connections
Set ihDestBlock = ihStream.Elements("Ports").Elements("DEST")
If (ihDestBlock.Elements.RowCount(0) > 0) Then
   ' there is a destination port
   strDestBlock = ihDestBlock.Elements(0).value
   strDestPort = ihBlockList.Elements(strDestBlock). _
   Connections.Elements(strStreamName).value
Else
   ' it's a flowsheet product
   strDestBlock = ""
   strDestPort = ""
End If
' get the source connections
Set ihSourceBlock = ihStream.Elements("Ports").Elements("SOURCE")
If (ihSourceBlock.Elements.RowCount(0) > 0) Then
   ' there is a source port
   strSourceBlock = ihSourceBlock.Elements(0).value
   strSourcePort = ihBlockList.Elements(strSourceBlock). _
   Connections.Elements(strStreamName).value
Else
   ' it's a flowsheet feed
   strSourceBlock = ""
   strSourcePort = ""
End If

strTable = strTable & Chr(13) & strStreamName _
          & Chr(9) & strSourceBlock _
          & Chr(9) & strSourcePort & Chr(9) _
          & Chr(9) & strDestBlock & Chr(9) _
          & strDestPort
Next ihStream
MsgBox strHeading & strTable, , "ConnectivityExample"
Exit Sub

ErrorHandler:
MsgBox "ConnectivityExample raised error" & Err & ": " & Error(Err)

End Sub

