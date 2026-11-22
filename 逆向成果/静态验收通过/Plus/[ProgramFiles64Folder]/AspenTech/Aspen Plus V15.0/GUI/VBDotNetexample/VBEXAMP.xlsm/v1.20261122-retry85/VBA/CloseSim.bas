Attribute VB_Name = "CloseSim"
Option Explicit
Sub Main()
Call CloseSimulation(CloseSimulation())
End Sub
Sub CloseSimulation(ByVal ihAPsim As IHapp)
    On Error GoTo ErrorHandler
    'Quit without saving
    ihAPsim.Quit
    Exit Sub
ErrorHandler:
    MsgBox "CloseSimulation raised error " & Err & ": " & Error(Err)
End Sub
