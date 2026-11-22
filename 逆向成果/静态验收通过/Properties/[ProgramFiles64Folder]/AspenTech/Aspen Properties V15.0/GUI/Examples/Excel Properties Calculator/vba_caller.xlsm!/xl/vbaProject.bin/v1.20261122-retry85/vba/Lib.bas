Attribute VB_Name = "Lib"
'''
''' Prints static library information to Immediate window.
'''
Public Sub PrintReferences()

Dim proj    As VBIDE.VBProject
Dim ref     As VBIDE.Reference
Dim icount  As Integer

    On Error Resume Next
    Set proj = ThisWorkbook.VBProject
    For Each ref In proj.References
        icount = icount + 1
        If ref.IsBroken Then
            Debug.Print Strings.String(110, "-")
            Debug.Print "["; icount; "] ** MISSING ** (T_T) ** "; ref.GUID
            Debug.Print Strings.String(110, "-")
        Else
            Debug.Print Strings.String(110, "=")
            Debug.Print "["; icount; "] "; ref.Description
            Debug.Print Strings.String(110, "=")
            Debug.Print "|> Name:", ref.Name
            Debug.Print "|> GUID:", ref.GUID
            Debug.Print "|> Major:", VBA.Trim$(ref.Major)
            Debug.Print "|> Minor:", VBA.Trim$(ref.Minor)
            Debug.Print "|> FullPath:", ref.fullPath
        End If
    Next ref
    
End Sub


