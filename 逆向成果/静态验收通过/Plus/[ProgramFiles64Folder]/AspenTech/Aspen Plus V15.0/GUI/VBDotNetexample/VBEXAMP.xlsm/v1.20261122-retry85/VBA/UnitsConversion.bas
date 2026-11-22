Attribute VB_Name = "UnitsConversion"


Option Explicit
Sub Main()
Attribute Main.VB_ProcData.VB_Invoke_Func = " \n14"
Call UnitsConversionExample(OpenSimulation())
End Sub


Sub UnitsConversionExample(ihAPsim As IHapp)
Attribute UnitsConversionExample.VB_ProcData.VB_Invoke_Func = " \n14"
' This example retrieves a value both in the display units (psi) and
' alternative units (atm)
Dim ihPres As IHNode
Dim nRow As Long
Dim nCol As Long
Dim strDisplayUnits As String
Dim strConvertedUnits As String
On Error GoTo ErrorHandler
Set ihPres = ihAPsim.Tree.Data.Blocks.B3.Output.B_PRES
' retrieve the attributes for the display units (psi)
nRow = ihPres.AttributeValue(HAP_UNITROW)
nCol = ihPres.AttributeValue(HAP_UNITCOL)
strDisplayUnits = UnitsString(ihAPsim, nRow, nCol)
'select the alternative unit table column (atm)
nCol = 3
strConvertedUnits = UnitsString(ihAPsim, nRow, nCol)
MsgBox "Pressure in Display units: " & ihPres.value & _
       " " & strDisplayUnits & Chr$(13) & _
       "Pressure in Converted units: " & _
       ihPres.ValueForUnit(nRow, nCol) & " " & strConvertedUnits, _
       , "UnitsConversionExample"
Exit Sub
ErrorHandler:
MsgBox "UnitsConversionExample raised error " & Err & ": " & Error(Err)
End Sub
Public Function UnitsString(ihAPsim As IHapp, nRow As Long, nCol As Long)
Attribute UnitsString.VB_ProcData.VB_Invoke_Func = " \n14"
' This function returns the units of measurement symbol given
' the unit table row and column
On Error GoTo UnitsStringFailed
UnitsString = ihAPsim.Tree.Elements("Unit Table"). _
              Elements(nRow - 1).Elements.Label(0, nCol - 1)
Exit Function
UnitsStringFailed:
UnitsString = ""
End Function


