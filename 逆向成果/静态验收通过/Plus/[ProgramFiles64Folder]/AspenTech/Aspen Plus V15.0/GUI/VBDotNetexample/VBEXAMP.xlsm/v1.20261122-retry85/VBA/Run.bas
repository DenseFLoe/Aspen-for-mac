Attribute VB_Name = "Run"


Option Explicit
Sub Main()
Attribute Main.VB_ProcData.VB_Invoke_Func = " \n14"
Call RunExample(OpenSimulation())
End Sub

Sub RunExample(ihAPsim As IHapp)
Attribute RunExample.VB_ProcData.VB_Invoke_Func = " \n14"
' This example changes a simulation parameter and re-runs the simulation
Dim ihEngine As IHAPEngine
Dim nStages As Variant
Dim strPrompt As String
On Error GoTo ErrorHandler
Set ihEngine = ihAPsim.Engine
EditSimulation:
nStages = ihAPsim.Tree.Data.Blocks.B6.Input.Elements("NSTAGE").value
strPrompt = "Existing number of stages for column B6 = " & nStages _
       & Chr(13) & "Enter new value for number of stages."
nStages = InputBox(strPrompt)
If (nStages = "") Then GoTo finish
' edit the simulation
ihAPsim.Tree.Data.Blocks.B6.Input.Elements("NSTAGE").value = nStages
' run the simulation
ihAPsim.Run
' look at the status and results
Call ListBlocksExample(ihAPsim)
Call TempProfExample(ihAPsim)
GoTo EditSimulation
finish:
Exit Sub
ErrorHandler:
MsgBox "RunExample failed with error " & Err & Chr(13) & Error(Err)
End Sub

