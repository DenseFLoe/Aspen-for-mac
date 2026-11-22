Attribute VB_Name = "Sheet14"
Attribute VB_Base = "0{00020820-0000-0000-C000-000000000046}"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = True
Attribute VB_TemplateDerived = False
Attribute VB_Customizable = True
Attribute VB_Control = "cmdOpenPkg, 18, 0, MSForms, CommandButton"
Attribute VB_Control = "cmdOK, 14, 1, MSForms, CommandButton"
Attribute VB_Control = "obCrystallization, 12, 2, MSForms, OptionButton"
Attribute VB_Control = "obTernaryPhaseDiagram, 11, 3, MSForms, OptionButton"
Attribute VB_Control = "obPhaseDiagramForVLLE, 10, 4, MSForms, OptionButton"
Attribute VB_Control = "obPhaseDiagramForVLE, 9, 5, MSForms, OptionButton"
Attribute VB_Control = "obSolubilityInTernarySolvents, 8, 6, MSForms, OptionButton"
Attribute VB_Control = "obSolubilityInBinarySolvents, 7, 7, MSForms, OptionButton"
Attribute VB_Control = "obHTPrediction, 6, 8, MSForms, OptionButton"
Attribute VB_Control = "obLogPCalculation, 5, 9, MSForms, OptionButton"
Attribute VB_Control = "obTemperatureEffect, 4, 10, MSForms, OptionButton"
Attribute VB_Control = "obFreeEnergyOfMixing, 3, 11, MSForms, OptionButton"
Attribute VB_Control = "obSolubilityInSolvents, 1, 12, MSForms, OptionButton"
Attribute VB_Control = "Image1, 17, 13, MSForms, Image"
Option Explicit

Private Const mSolventListPage = "Solvent List"
Private Const mSolubilityInSolventsPage = "Solubility in Solvents"
Private Const mFreeEnergyOfMixingPage = "Free Energy of Mixing"
Private Const mTemperatureEffectPage = "Temperature Effect"
Private Const mLogPCalculationPage = "logP Calculation"
Private Const mHTMiscibilityPredictionPage = "HT Miscibility Prediction"
Private Const mHighThroughputPredictionPage = "High Throughput Prediction"
Private Const mSolubilityInBinarySolventsPage = "Solubility in Binary Solvents"
Private Const mSolubilityInTernarySolventsPage = "Solubility in Ternary Solvents"
Private Const mPhaseDiagramForVLEPage = "Phase Diagrams for VLE"
Private Const mPhaseDiagramForVLLEPage = "Phase Diagrams for VLLE"
Private Const mTernaryPhaseDiagramPage = "Ternary Phase Diagram"
Private Const mCrystallizationPage = "Crystallization-Add"

Private Sub cmdOK_Click()
Dim Sheet As Object

On Error GoTo errorhandler


    Sheets(mSolventListPage).Visible = xlSheetVisible

    If obSolubilityInSolvents.Value = True Then
        With Sheets(mSolubilityInSolventsPage)
            .Visible = xlSheetVisible
            For Each Sheet In Sheets
              If Not (Sheet.Name = mSolubilityInSolventsPage Or Sheet.Name = mSolventListPage) Then
                Sheet.Visible = xlSheetVeryHidden
              End If
            Next
        End With
        
        Exit Sub
    End If
    
    If obFreeEnergyOfMixing.Value = True Then
        With Sheets(mFreeEnergyOfMixingPage)
            .Visible = xlSheetVisible
            For Each Sheet In Sheets
              If Not (Sheet.Name = mFreeEnergyOfMixingPage Or Sheet.Name = mSolventListPage) Then
                Sheet.Visible = xlSheetVeryHidden
              End If
            Next
        End With
        Exit Sub
    End If
    
    If obTemperatureEffect.Value = True Then
        With Sheets(mTemperatureEffectPage)
            .Visible = xlSheetVisible
            For Each Sheet In Sheets
              If Not (Sheet.Name = mTemperatureEffectPage Or Sheet.Name = mSolventListPage) Then
                Sheet.Visible = xlSheetVeryHidden
              End If
            Next
        End With
        Exit Sub
    End If
    
    If obLogPCalculation.Value = True Then
        With Sheets(mLogPCalculationPage)
            .Visible = xlSheetVisible
            For Each Sheet In Sheets
              If Not (Sheet.Name = mLogPCalculationPage Or Sheet.Name = mSolventListPage) Then
                Sheet.Visible = xlSheetVeryHidden
              End If
            Next
        End With
        Exit Sub
    End If
    
    If obHTPrediction.Value = True Then
        'Sheets(mHTMiscibilityPredictionPage).Visible = xlSheetVeryHidden
        Sheets(mHighThroughputPredictionPage).Visible = xlSheetVisible
        For Each Sheet In Sheets
        If Not (Sheet.Name = mHighThroughputPredictionPage Or Sheet.Name = mSolventListPage) Then
          'If Not (Sheet.Name = mHTMiscibilityPredictionPage Or Sheet.Name = mHighThroughputPredictionPage Or Sheet.Name = mSolventListPage) Then
            Sheet.Visible = xlSheetVeryHidden
          End If
        Next
        Exit Sub
    End If
    
    If obSolubilityInBinarySolvents.Value = True Then
        With Sheets(mSolubilityInBinarySolventsPage)
            .Visible = xlSheetVisible
            For Each Sheet In Sheets
              If Not (Sheet.Name = mSolubilityInBinarySolventsPage Or Sheet.Name = mSolventListPage) Then
                Sheet.Visible = xlSheetVeryHidden
              End If
            Next
        End With
        Exit Sub
    End If
    
    If obSolubilityInTernarySolvents.Value = True Then
        With Sheets(mSolubilityInTernarySolventsPage)
            .Visible = xlSheetVisible
            For Each Sheet In Sheets
              If Not (Sheet.Name = mSolubilityInTernarySolventsPage Or Sheet.Name = mSolventListPage) Then
                Sheet.Visible = xlSheetVeryHidden
              End If
            Next
        End With
        Exit Sub
    End If
    
    If obPhaseDiagramForVLE.Value = True Then
        With Sheets(mPhaseDiagramForVLEPage)
            .Visible = xlSheetVisible
            For Each Sheet In Sheets
              If Not (Sheet.Name = mPhaseDiagramForVLEPage Or Sheet.Name = mSolventListPage) Then
                Sheet.Visible = xlSheetVeryHidden
              End If
            Next
        End With
        Exit Sub
    End If
    
    If obPhaseDiagramForVLLE.Value = True Then
        With Sheets(mPhaseDiagramForVLLEPage)
            .Visible = xlSheetVisible
            For Each Sheet In Sheets
              If Not (Sheet.Name = mPhaseDiagramForVLLEPage Or Sheet.Name = mSolventListPage) Then
                Sheet.Visible = xlSheetVeryHidden
              End If
            Next
        End With
        Exit Sub
    End If
    
    If obTernaryPhaseDiagram.Value = True Then
        With Sheets(mTernaryPhaseDiagramPage)
            .Visible = xlSheetVisible
            For Each Sheet In Sheets
              If Not (Sheet.Name = mTernaryPhaseDiagramPage Or Sheet.Name = mSolventListPage) Then
                Sheet.Visible = xlSheetVeryHidden
              End If
            Next
        End With
        Exit Sub
    End If
    
    If obCrystallization.Value = True Then
        With Sheets(mCrystallizationPage)
            .Visible = xlSheetVisible
            For Each Sheet In Sheets
              If Not (Sheet.Name = mCrystallizationPage Or Sheet.Name = mSolventListPage) Then
                Sheet.Visible = xlSheetVeryHidden
              End If
            Next
        End With
        Exit Sub
    End If
    
    Exit Sub
    
errorhandler:

MsgBox "Error catched when going to the designated worksheet."
    
End Sub

Private Sub cmdOpenPkg_Click()
    Application.Run "COMAddinHelper.SelectPackage"
End Sub

Private Sub Worksheet_Activate()
        Dim bflag As Boolean
        bflag = ActiveSheet.EnableCalculation
        ActiveSheet.Calculate
        ActiveSheet.EnableCalculation = bflag

    gbAddinInstalled = CheckAddInInstalled1
End Sub

Private Sub Worksheet_Calculate()
    gbAddinInstalled = CheckAddInInstalled1
End Sub
Private Sub Worksheet_SelectionChange(ByVal Target As Range)
    gbAddinInstalled = CheckAddInInstalled1
End Sub
