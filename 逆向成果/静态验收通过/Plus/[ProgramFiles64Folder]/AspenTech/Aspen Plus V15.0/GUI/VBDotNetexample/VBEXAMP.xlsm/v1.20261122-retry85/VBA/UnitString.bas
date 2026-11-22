Attribute VB_Name = "UnitString"


Option Explicit
Sub Main()
Attribute Main.VB_ProcData.VB_Invoke_Func = " \n14"
Call UnitStringExample(OpenSimulation())
End Sub


Sub UnitStringExample(ihAPsim As IHapp)
Attribute UnitStringExample.VB_ProcData.VB_Invoke_Func = " \n14"
' This example retrieves the units of measurement symbol for a
' variable
Dim ihPresNode As IHNode
On Error GoTo ErrorHandler
Set ihPresNode = ihAPsim.Tree.Data.Blocks.B3.Output.B_PRES
MsgBox "Flash pressure is: " & ihPresNode.value & Chr(9) & _
         ihPresNode.UnitString, , "UnitStringExample"
Exit Sub
ErrorHandler:
MsgBox "UnitStringExample raised error " & Err & ": " & Error(Err)
End Sub


