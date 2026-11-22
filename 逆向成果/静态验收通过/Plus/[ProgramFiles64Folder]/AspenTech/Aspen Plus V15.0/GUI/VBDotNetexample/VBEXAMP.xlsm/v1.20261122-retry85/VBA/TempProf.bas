Attribute VB_Name = "TempProf"


Option Explicit
Sub Main()
Attribute Main.VB_ProcData.VB_Invoke_Func = " \n14"
Call TempProfExample(OpenSimulation())
End Sub


Sub TempProfExample(ihAPsim As IHapp)
Attribute TempProfExample.VB_ProcData.VB_Invoke_Func = " \n14"
' This example retrieves values for a non-scalar variable with
' one identifier
Dim ihTVar As IHNode
Dim ihStage As IHNode
Dim strOut As String
On Error GoTo ErrorHandler
Set ihTVar = ihAPsim.Tree.Data.Blocks.B6.Output.B_TEMP
strOut = ihTVar.Elements.DimensionName(0) & Chr(9) & ihTVar.Name
For Each ihStage In ihTVar.Elements
   strOut = strOut & Chr(13) & ihStage.Name _
   & Chr(9) & Format(ihStage.value, "###.00") _
   & Chr(9) & ihStage.UnitString
Next ihStage
MsgBox strOut, , "TempProfExample"
Exit Sub
ErrorHandler:
MsgBox "TempProfExample raised error " & Err & ": " & Error(Err)
End Sub





