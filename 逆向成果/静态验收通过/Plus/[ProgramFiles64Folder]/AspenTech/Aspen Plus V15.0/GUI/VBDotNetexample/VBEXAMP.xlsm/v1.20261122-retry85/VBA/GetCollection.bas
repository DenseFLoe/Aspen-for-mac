Attribute VB_Name = "GetCollection"


Option Explicit

Sub Main()
Attribute Main.VB_ProcData.VB_Invoke_Func = " \n14"
Call GetCollectionExample(OpenSimulation())
End Sub

Sub GetCollectionExample(ihAPsim As IHapp)
Attribute GetCollectionExample.VB_ProcData.VB_Invoke_Func = " \n14"
' This example illustrates use of a collection object
Dim ihRoot As IHNode
Dim ihcolOffspring As IHNodeCol
Dim ihOffspring As IHNode
Dim strOut As String
On Error GoTo ErrorHandler
'get the root of the tree
Set ihRoot = ihAPsim.Tree
'now get the collection of nodes immediately below the Root
Set ihcolOffspring = ihRoot.Elements
For Each ihOffspring In ihcolOffspring
   strOut = strOut & Chr(13) & ihOffspring.Name
Next
MsgBox "Offspring nodes are: " & strOut, , "GetCollectionExample"
Exit Sub
ErrorHandler:
MsgBox "GetCollectionExample raised error" & Err & ": " & Error(Err)
End Sub

