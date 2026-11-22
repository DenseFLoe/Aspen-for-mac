Attribute VB_Name = "ListBlocks"


Option Explicit
Sub Main()
Attribute Main.VB_ProcData.VB_Invoke_Func = " \n14"
Dim ihAPsim As IHapp
Call ListBlocksExample(OpenSimulation())
End Sub


Sub ListBlocksExample(ihAPsim As IHapp)
Attribute ListBlocksExample.VB_ProcData.VB_Invoke_Func = " \n14"
' This example retrieves a list of blocks and their attributes
Dim ihBlockList As IHNodeCol
Dim ihBlock As IHNode
Dim strOut As String
On Error GoTo ErrorHandler
Set ihBlockList = ihAPsim.Tree.Data.Blocks.Elements
strOut = "Block" & Chr(9) & "Block Type" _
         & Chr(9) & "Section  " & Chr(9) & "Results status"
For Each ihBlock In ihBlockList
strOut = strOut & Chr(13) & ihBlock.Name & Chr(9) & _
    ihBlock.AttributeValue(HAP_RECORDTYPE) & "  " & Chr(9) & _
    ihBlock.AttributeValue(HAP_SECTION) & Chr(9) & _
    Status(ihBlock.AttributeValue(HAP_COMPSTATUS))
Next ihBlock
MsgBox strOut, , "ListBlocksExample"
Exit Sub
ErrorHandler:
MsgBox "ListBlocksExample raised error" & Err & ": " & Error(Err)
End Sub

Function Status(CompStat As Long) As String
Attribute Status.VB_ProcData.VB_Invoke_Func = " \n14"
' This function interprets a status variable and returns a string

If ((CompStat And HAP_RESULTS_SUCCESS) = HAP_RESULTS_SUCCESS) Then
   Status = "Success"
ElseIf ((CompStat And HAP_RESULTS_ERRORS) = HAP_RESULTS_ERRORS) Then
   Status = "Errors"
ElseIf ((CompStat And HAP_RESULTS_WARNINGS) = HAP_RESULTS_WARNINGS) Then
   Status = "Warnings"
ElseIf ((CompStat And HAP_NORESULTS) = HAP_NORESULTS) Then
   Status = "No results"
ElseIf ((CompStat And HAP_RESULTS_INCOMPAT) = HAP_RESULTS_INCOMPAT) Then
   Status = "Incompatible with input"
ElseIf ((CompStat And HAP_RESULTS_INACCESS) = HAP_RESULTS_INACCESS) Then
   Status = "In access"
End If
End Function









