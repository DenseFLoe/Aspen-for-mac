Attribute VB_Name = "GetScalarValues"


Option Explicit
Sub Main()
Attribute Main.VB_ProcData.VB_Invoke_Func = " \n14"
Call GetScalarValuesExample(OpenSimulation())
End Sub



Sub GetScalarValuesExample(ihAPsim As IHapp)
Attribute GetScalarValuesExample.VB_ProcData.VB_Invoke_Func = " \n14"
' This example retrieves scalar variables from a block
Dim ihColumn As IHNode
Dim nStages As Long
Dim buratio As Double
On Error GoTo ErrorHandler
' navigate the tree to the RADFRAC block
Set ihColumn = ihAPsim.Tree.Data.Blocks.B6
' get the number of stages
nStages = ihColumn.Input.Elements("NSTAGE").value
' get the boilup ratio
buratio = ihColumn.Output.Elements("BU_RATIO").value
MsgBox "Number of Stages is: " & nStages & Chr(13) _
      & "Boilup Ratio is: " & buratio, , "GetScalarValuesExample"
Exit Sub
ErrorHandler:
MsgBox "GetScalarValuesExample raised error" & Err & ": " & Error(Err)
End Sub


