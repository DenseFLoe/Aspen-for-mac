Attribute VB_Name = "LogFile"
Attribute VB_Base = "0{FCFB3D2A-A0FA-1068-A738-08002B3371B5}"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Attribute VB_TemplateDerived = False
Attribute VB_Customizable = False
' By Brian J. Satola, a simplified version of the following and does not make Registry read/writes:
' https://chejunkie.com/knowledge-base/the-log-file-class-vba/

'==========================================================================================================================
' Application constants
'==========================================================================================================================
Private Const C_FILE_EXT                As String = ".txt"
Private Const C_MAX_LEN                 As Integer = 96 ' size/length of header boarders. (MUST BE AN EVEN NUMBER!)
                                                        ' 96 seems to be a good size for wide-screen, else 90 or lower.
Private Enum LogOutputType
    LogAppend = 1
    LogOutput = 2
End Enum

Public Enum LogFormat
    LogTitle
    LogHeader1
    LogHeader2
    LogDefault
    LogBullet1
    LogBullet2
    LogNoFormat
    LogLineThru
End Enum

'==========================================================================================================================
' Private variables
'==========================================================================================================================
Dim m_FullName As String ' log file path
Dim m_LogFileExists As Boolean
'

'''
''' Logs the message to the defined log file.
''' Formats the output according to LogFormatType.
'''
Public Sub Log(ByVal message As String, Optional format As LogFormat = LogFormat.LogNoFormat, Optional blankLineBeforeHeader As Boolean = True)

Dim strg                As String
Dim pads(2)             As String
Dim nlen(2)             As Integer
Dim ilen                As Long
    
'//========================================================================================================================
'// Optional Message Formatting
'//========================================================================================================================

    Select Case format
    
        '//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        '////               ///////////////////////////////////////////////////////////////////////////////////////////////
        '////   LOG TITLE   ///////////////////////////////////////////////////////////////////////////////////////////////
        '////               ///////////////////////////////////////////////////////////////////////////////////////////////
        '//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Case LogFormat.LogTitle
        
            '// Preformatting
            '   [1] Padding for "message line.
            '   [2] Padding for spacer line.
            nlen(1) = Int(C_MAX_LEN * 1.5) - (VBA.Len(message) + 12)
            For ilen = 1 To nlen(1)
                pads(1) = pads(1) & "/"
            Next ilen
            pads(1) = "    " & pads(1)
            
            nlen(2) = VBA.Len(message)
            For ilen = 1 To nlen(2)
                pads(2) = pads(2) & " "
            Next ilen
            
            '// Title definition.
            If blankLineBeforeHeader Then
                strg = VBA.vbCrLf & VBA.vbCrLf
            End If
            strg = strg & String(Int(C_MAX_LEN * 1.5), "/") & VBA.vbCrLf
            strg = strg & "////    " & pads(2) & pads(1) & VBA.vbCrLf
            strg = strg & "////    " & message & pads(1) & VBA.vbCrLf
            strg = strg & "////    " & pads(2) & pads(1) & VBA.vbCrLf
            strg = strg & String(Int(C_MAX_LEN * 1.5), "/") & VBA.vbCrLf
            message = strg
        
        '==================================================================================================================
        'LOG HEADER NO. 1
        '==================================================================================================================
        Case LogFormat.LogHeader1
            
            '// Preformatting
            If blankLineBeforeHeader Then
                strg = VBA.vbCrLf
            End If
            '// Header definition
            strg = strg & String(Int(C_MAX_LEN * 1.25), "=") & VBA.vbCrLf
            strg = strg & message & VBA.vbCrLf
            strg = strg & String(Int(C_MAX_LEN * 1.25), "=")
            message = strg
            
        '------------------------------------------------------------------------------------------------------------------
        'LOG HEADER NO. 2
        '------------------------------------------------------------------------------------------------------------------
        Case LogFormat.LogHeader2
            
            '// Preformatting
            If blankLineBeforeHeader Then
                strg = VBA.vbCrLf
            End If
            '// Header definition
            strg = strg & String(C_MAX_LEN, "-") & VBA.vbCrLf
            strg = strg & message & VBA.vbCrLf
            strg = strg & String(C_MAX_LEN, "-")
            message = strg
        
        '__________________________________________________________________________________________________________________
        '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
        Case LogFormat.LogDefault:          message = VBA.Now & ": " & message
        Case LogFormat.LogBullet1:          message = VBA.Now & ": |> " & message
        Case LogFormat.LogBullet2:          message = VBA.Now & ": |--> " & message
        Case LogFormat.LogNoFormat
        
        Case LogFormat.LogLineThru
            nlen(1) = C_MAX_LEN - VBA.Len(VBA.Now & ": ")
            If (VBA.Len(message) <= nlen(1)) Then
                strg = VBA.Replace(message, " ", "-")
                strg = "---" & strg
                nlen(2) = nlen(1) - VBA.Len(message) - 3
                For ilen = 1 To nlen(2)
                    strg = strg & "-"
                Next ilen
                message = VBA.Now & ": " & strg
            End If
            
        Case Else ' display error message
            '--With m_AppErr
            '--    .Number = C_ERR_INVALID_INPUT
            '--    .Source = "LogString(...)"
            '--    .Description = GetAppErrDescription(.Number)
            '--    .DisplayMessage
            '--End With
            Exit Sub
    End Select
    
'//========================================================================================================================
'// Write Message to Logfile
'//========================================================================================================================
    Call WriteToFile(message, LogAppend)

End Sub

Public Sub LogLine(chr As String)

    Call WriteToFile(String(Int(C_MAX_LEN * 1.25), chr), LogAppend)

End Sub

'''
''' Writes "message" to the current log file.
'''
Private Sub WriteToFile(message As String, outputType As LogOutputType)

Dim lu          As Integer

    If Not m_LogFileExists Then
        m_LogFileExists = CreateLogFile()
    End If
    If Not m_LogFileExists Then
        MsgBox "Problem creating log file."
        Stop
        Exit Sub
    End If
    
    On Error Resume Next
    lu = VBA.FreeFile
    
    Select Case outputType
        Case LogAppend: Open m_FullName For Append As #lu
        Case LogOutput: Open m_FullName For Output As #lu
    End Select
    
    Print #lu, message
    Close #lu

End Sub

'''
''' Creates a log file for output and stores it in the specified [storageDirectory].
''' If no [storageDirectory] is provided, then the [DirectoryPath] property is used.
'''
Private Function CreateLogFile() As Boolean

Dim path        As String
Dim sfx         As String
Dim i           As Integer
Dim logName     As String

'//========================================================================================================================
'// Initialize
'//========================================================================================================================

    path = ThisWorkbook.path '--storageDirectory
    If (VBA.Right(VBA.Trim(path), 1) <> "\") Then
        path = VBA.Trim(path) & "\"
    End If
    If Not (VBA.Dir(path, vbDirectory) = ".") Then
        path = "" ' defaults to C:\Users\<user>\Documents
    End If
    
    logName = VBA.Mid$(ThisWorkbook.Name, 1, VBA.InStrRev(ThisWorkbook.Name, ".") - 1) & " Log"
    m_FullName = path & logName & C_FILE_EXT
    

'==========================================================================================================================
' Define LogFileName
'==========================================================================================================================

    '// Ensure unique name (use integer suffix until found)
    Do Until (FileFolderExists(m_FullName) = False)
        i = i + 1
        sfx = " (" & i & ")"
        m_FullName = path & logName & sfx & C_FILE_EXT
    Loop

'//========================================================================================================================
'// Print Logfile Header
'//========================================================================================================================

    '// Function WriteToFile(ByVal strLogMessage As String, ByVal iTypeOutput As EOutputType) As Boolean
    m_LogFileExists = True
    Call WriteToFile(VBA.Now, LogAppend)
    CreateLogFile = True
    
End Function

'''
''' Function returns TRUE if the specified file or folder exists, FALSE if not.
'''
Private Function FileFolderExists(fullPath As String) As Boolean
    
    On Error Resume Next
    
    If Not (Dir(fullPath, vbDirectory) = vbNullString) And (fullPath <> vbNullString) Then
        FileFolderExists = True
    End If
    
End Function

'''
''' Opens the current log file (if it exists).
'''
Public Sub OpenLogger()

    Call OpenFileFolder(m_FullName)
    
End Sub

'''
''' Opens the file/folder by the specified <path>.
'''
Private Sub OpenFileFolder(fullPath As String)
    
    '--m_AppErr.Clear
    
    On Error Resume Next
    Excel.ActiveWorkbook.FollowHyperlink Address:=fullPath, NewWindow:=True
    Select Case Err.Number
        Case 0, -2147467260 '(-2147467260) results when someone hits cancel on Excel prompt.
            Exit Sub
        Case Else
            '--On Error Resume Next
            '--With m_AppErr
            '--    If (VBA.InStr(VBA.Mid(fullPath, VBA.Len(fullPath) - VBA.Len(m_FileExt) - 1, VBA.Len(m_FileExt)), ".") <> 0) Then
            '--        .Number = C_ERR_INVALID_FILE
            '--    Else
            '--        .Number = C_ERR_INVALID_DIRECTORY
            '--    End If
            '--    .Source = "OpenFileFolder(...)"
            '--    .Description = GetAppErrDescription(.Number)
            '--End With
            Call MsgBox("Invalid file or directory path.", vbOKOnly + vbExclamation, "Failed to Open")
    End Select
   
End Sub

Public Function FullName() As String
    
    If (m_FullName = "") Then
        m_LogFileExists = CreateLogFile()
    End If
    LogFilePath = m_FullName
    
End Function

