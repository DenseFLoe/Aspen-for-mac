Attribute VB_Name = "OpenSim"


Option Explicit
Sub Main()
Attribute Main.VB_ProcData.VB_Invoke_Func = " \n14"
Dim ihAPsim As IHapp
Set ihAPsim = OpenSimulation()
End Sub
Function readFromRegistry(strRegistryKey, strDefault)
    Dim WSHShell As WSHShell, value

    On Error Resume Next
    Set WSHShell = CreateObject("WScript.Shell")
    value = WSHShell.RegRead(strRegistryKey)

    If Err.Number <> 0 Then
        readFromRegistry = strDefault
    Else
        readFromRegistry = value
    End If

    WSHShell = Nothing
    Err.Clear
    
End Function
    

Function OpenSimulation() As IHapp
Attribute OpenSimulation.VB_ProcData.VB_Invoke_Func = " \n14"
Dim ihAPsim As IHapp
On Error GoTo ErrorHandler
' set A+ version
Dim VERSION As String
Dim strkey As String
Dim path As String
Dim windowsShell
Dim VERSIONNUMBER
VERSION = "V15.0"
VERSIONNUMBER = "41.0"
       
' set the path to the AspenPlus examples folder
strkey = "HKEY_LOCAL_MACHINE\SOFTWARE\AspenTech\Aspen Plus\" + VERSIONNUMBER + "\mm\mmtop"
path = readFromRegistry(strkey, "")
'If path = "" Then
'    strkey = "HKEY_LOCAL_MACHINE\SOFTWARE\Wow643\AspenTech\Aspen Plus\" + VERSIONNUMBER + "\mm"
'    path = readFromRegistry(strkey, "")
'End If

If path = "" Then
  path = "c:\Program Files\AspenTech\Aspen Plus " + VERSION + "\GUI"
End If

path = path + "\Examples\Bulk Chemicals\"

' open existing simulation
Set ihAPsim = _
  GetObject(path + "pfdtut.bkp")
' display the GUI
ihAPsim.Visible = True
Set OpenSimulation = ihAPsim
Exit Function
ErrorHandler:
MsgBox "OpenSimulation raised error " & Err & ": " & Error(Err)
End
End Function

