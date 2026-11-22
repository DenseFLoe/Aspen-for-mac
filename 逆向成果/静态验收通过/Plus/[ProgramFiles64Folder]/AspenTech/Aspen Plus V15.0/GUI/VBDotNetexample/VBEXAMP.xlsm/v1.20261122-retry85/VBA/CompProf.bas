Attribute VB_Name = "CompProf"



Option Explicit
Sub Main()
Attribute Main.VB_ProcData.VB_Invoke_Func = " \n14"
Call CompProfExample(OpenSimulation())
End Sub


Sub CompProfExample(ihAPsim As IHapp)
Attribute CompProfExample.VB_ProcData.VB_Invoke_Func = " \n14"
' This example retrieves values for a non-scalar variable with
' two identifiers
Dim ihTrayNode As IHNode
Dim ihXNode As IHNode
Dim ihCompNode As IHNode
Dim strOut As String
Dim nLines As Integer
On Error GoTo ErrorHandler
Set ihXNode = ihAPsim.Tree.Data.Blocks.B6.Output.Elements("X")
nLines = 0
For Each ihTrayNode In ihXNode.Elements
   For Each ihCompNode In ihTrayNode.Elements
      strOut = strOut & Chr(13) & ihTrayNode.Name & _
               Chr(9) & ihCompNode.Name & Chr(9) & _
               ihCompNode.value
      nLines = nLines + 1
      If nLines = 40 Then
        MsgBox strOut, , "CompProfExample"
        strOut = ""
        nLines = 0
      End If
   Next ihCompNode
Next ihTrayNode
If nLines > 0 Then
    MsgBox strOut, , "CompProfExample"
End If
Exit Sub
ErrorHandler:
MsgBox "CompProfExample raised error " & Err & ": " & Error(Err)
End Sub


