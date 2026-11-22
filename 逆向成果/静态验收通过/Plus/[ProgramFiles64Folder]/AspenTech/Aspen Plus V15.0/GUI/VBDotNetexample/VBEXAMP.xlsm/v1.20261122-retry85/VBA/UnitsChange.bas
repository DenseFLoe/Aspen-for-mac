Attribute VB_Name = "UnitsChange"


Option Explicit
Sub Main()
Attribute Main.VB_ProcData.VB_Invoke_Func = " \n14"
Call UnitsChangeExample(OpenSimulation())
End Sub

Sub UnitsChangeExample(ihAPsim As IHapp)
Attribute UnitsChangeExample.VB_ProcData.VB_Invoke_Func = " \n14"
' This example shows changing the units of measurement of a variable
Dim ihPres As IHNode
On Error GoTo ErrorHandler
Set ihPres = ihAPsim.Tree.Data.Blocks.B3.Output.B_PRES
MsgBox "Pressure in default units: " _
              & ihPres.value _
              & Chr(9) & ihPres.UnitString
' change units of measurement to bar
ihPres.AttributeValue(HAP_UNITCOL, True) = 5
MsgBox "Pressure in selected units: " _
              & ihPres.value _
              & Chr(9) & ihPres.UnitString
Exit Sub
ErrorHandler:
MsgBox "UnitsChangeExample raised error " & Err & ": " & Error(Err)
End Sub


