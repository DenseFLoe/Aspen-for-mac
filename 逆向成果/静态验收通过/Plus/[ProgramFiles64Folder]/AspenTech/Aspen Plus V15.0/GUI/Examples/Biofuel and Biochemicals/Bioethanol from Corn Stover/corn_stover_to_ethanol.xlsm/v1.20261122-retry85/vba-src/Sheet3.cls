Attribute VB_Name = "Sheet3"
Attribute VB_Base = "0{00020820-0000-0000-C000-000000000046}"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = True
Attribute VB_TemplateDerived = False
Attribute VB_Customizable = True
Attribute VB_Control = "cmd_RunMEBTool, 5, 1, MSForms, CommandButton"
Attribute VB_Control = "cmd_UpdateFileName, 4, 2, MSForms, CommandButton"
Attribute VB_Control = "ComboBox2, 2, 3, MSForms, ComboBox"
Attribute VB_Control = "ComboBox1, 1, 4, MSForms, ComboBox"
Option Explicit

Private Sub cmd_UpdateFileName_Click()
    
' This routine handles the "Update File Name" button
    
    Dim InitialRow As Integer
    Dim InitialCol As Integer
        
' Store the original cell location

    InitialRow = Selection.Row
    InitialCol = Selection.Column
    
' Pick the simulation file name

    PickSimulationFileName ActiveSheet.Range("B1")

' Reset cell focus to the original location

    Cells(InitialRow, InitialCol).Select
    
End Sub

Private Sub cmd_RunMEBTool_Click()

' This routine handles the "Run MEB Tool" button

    Dim InitialRow As Integer
    Dim InitialCol As Integer
        
' Store the original cell location

    InitialRow = Selection.Row
    InitialCol = Selection.Column
    
' Run the tool

    Run_MEBTool

' Reset cell focus to the original location

    Cells(InitialRow, InitialCol).Select
    
End Sub

