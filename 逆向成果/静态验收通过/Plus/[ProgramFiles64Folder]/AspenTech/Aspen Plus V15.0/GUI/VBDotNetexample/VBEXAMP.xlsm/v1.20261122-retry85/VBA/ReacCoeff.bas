Attribute VB_Name = "ReacCoeff"


Option Explicit
Sub Main()
Attribute Main.VB_ProcData.VB_Invoke_Func = " \n14"
Call ReacCoeffExample(OpenSimulation())
End Sub



Sub ReacCoeffExample(ihAPsim As IHapp)
Attribute ReacCoeffExample.VB_ProcData.VB_Invoke_Func = " \n14"
' This example retrieves values for a non-scalar variable with
' three identifiers
Dim ihReacNode As IHNode
Dim ihCoeffNode As IHNode
Dim intOff As Long
Dim strHeading As String
Dim strTable As String
Dim nReacCoeff As Integer
On Error GoTo ErrorHandler
Set ihCoeffNode = ihAPsim.Tree.Data.Blocks.B2.Input.COEF
' loop through reaction nodes
For Each ihReacNode In ihCoeffNode.Elements
  strHeading = ihCoeffNode.Elements.DimensionName(0) _
    & Chr(9) & ihReacNode.Elements.DimensionName(0) _
    & Chr(9) & ihReacNode.Elements.DimensionName(1)
  nReacCoeff = ihReacNode.Elements.RowCount(0)
  ' loop through coefficient nodes retrieving component and substream
  ' identifiers and coefficient values
  For intOff = 0 To nReacCoeff - 1
    strTable = strTable & Chr(13) & ihReacNode.Name & Chr(9) _
    & Chr(9) & ihReacNode.Elements.Label(0, intOff) & Chr(9) _
    & Chr(9) & ihReacNode.Elements.Label(1, intOff) & Chr(9) _
    & Chr(9) & ihReacNode.Elements.Item(intOff, intOff).value
  Next intOff
  MsgBox strHeading & strTable, , "ReacCoeffExample"
Next ihReacNode
Exit Sub
ErrorHandler:
MsgBox "ReacCoeffExample raised error " & Err & ": " & Error(Err)
End Sub



