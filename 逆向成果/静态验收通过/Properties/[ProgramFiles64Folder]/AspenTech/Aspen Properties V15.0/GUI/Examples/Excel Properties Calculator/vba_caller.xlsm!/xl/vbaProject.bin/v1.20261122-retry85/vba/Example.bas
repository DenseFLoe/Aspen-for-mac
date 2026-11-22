Attribute VB_Name = "Example"
Option Explicit
Option Base 1
'
Private m_PackageChoice As Long
Private Enum PackageChoice
    TEST_DEFAULT = 0
    TEST_APRBKP = 1
End Enum
'
Private m_TestChoice As Long
Private Enum RunTest
    TEST_ALL = 0
    TEST_PURE = 1
    TEST_CONSTANT = 2
    TEST_PL = 3
    TEST_MIXTURE = 4
    TEST_FLASH = 5
    TEST_OTHER = 6
End Enum
'
Private Logger As New LogFile
'

Private Sub Main()

    Dim tt As Double    ' temperature
    Dim pp As Double    ' pressure
    Dim vfrac As Double ' vapor fraction
    
    m_PackageChoice = PackageChoice.TEST_DEFAULT
                                ' 0 = Default package
                                ' 1 = Aspen Properties file
    
    m_TestChoice = RunTest.TEST_OTHER
                                ' 0 = ALL
                                ' 1 = PURE
                                ' 2 = CONSTANT
                                ' 3 = VAPOR PRESSURE
                                ' 4 = MIXTURE
                                ' 5 = FLASH
                                ' 6 = OTHER
    
    tt = 320    ' K
    pp = 101325 ' Pa
    vfrac = 0

    '// Returns:
    '   1. Array of double values (length component list)
    '   2. Error message
    If (m_TestChoice = RunTest.TEST_ALL Or m_TestChoice = RunTest.TEST_PURE) Then
        Call PurePropertyTests(tt, pp)
    End If
    
    '// Returns:
    '   1. Double value
    '   2. Array of double values (length component list)
    '   3. Error message
    If (m_TestChoice = RunTest.TEST_ALL Or m_TestChoice = RunTest.TEST_MIXTURE) Then
        Call MixturePropertyTests(tt, pp)
    End If
    
    '// Returns:
    '   1. Array of double values (length component list)
    '   2. Error message
    If (m_TestChoice = RunTest.TEST_ALL Or m_TestChoice = RunTest.TEST_CONSTANT) Then
        Call PureComponentConstantTest
    End If
    
    '// Returns:
    '   1. Double value
    '   2. Array of double values (length component list)
    '   3. Error message
    If (m_TestChoice = RunTest.TEST_ALL Or m_TestChoice = RunTest.TEST_FLASH) Then
        Call FlashPropertyTest(tt, pp, vfrac, PV_VLE)
    End If
    
    '// Returns:
    '   1. Array of double values (length component list)
    If (m_TestChoice = RunTest.TEST_ALL Or m_TestChoice = RunTest.TEST_PL) Then
        Call VaporPressureTest(tt)
    End If
    
    '// Other
    If (m_TestChoice = RunTest.TEST_OTHER Or m_TestChoice = RunTest.TEST_ALL) Then
        Call OtherTests
    End If
    
    Logger.OpenLogger
    
End Sub

Private Function GetPackageName() As String

    If (m_PackageChoice = PackageChoice.TEST_DEFAULT) Then
        GetPackageName = "default"
    ElseIf (m_PackageChoice = PackageChoice.TEST_APRBKP) Then
        GetPackageName = ThisWorkbook.path & "\properties.aprbkp"
    Else
        GetPackageName = ""
    End If

End Function

Private Sub ValidateConnection(conn As VBConnection)

    If conn Is Nothing Then
        Set conn = GetConnection
    End If
    If (conn.IsDefined = False) Then
        Call conn.Initialize(GetPackageName())
        If (conn.IsDefined = False) Then
            Err.Raise vbObjectError + 9000, "Example.ValidateConnection", "Failed to connect to package source."
        End If
    End If
    
End Sub

Private Sub OtherTests(Optional conn As VBConnection)

    UnitsConversionTests
    AverageMolecularWeightTests
    MoleFlowToMoleFractionTests
    MoleFractionToMassFractionTests
    MassFlowToMoleFractionTests
    MassFractionToMoleFractionTests

End Sub

Private Sub AverageMolecularWeightTests(Optional conn As VBConnection)

    ValidateConnection conn
    
    Dim components As Variant
    Dim ncomp As Integer
    components = conn.Package.GetComponents
    ncomp = (UBound(components) - LBound(components)) + 1
    
    '==============================================================================================================
    ' AVERAGE MOLECULAR WEIGHT TEST
    '==============================================================================================================
    
    Logger.Log "AVERAGE MOLECULAR WEIGHT TEST", LogTitle
    
    Dim total As Double
    Dim moleFraction As Variant
    Dim i As Integer
    total = 1#
    ReDim moleFractions(1 To ncomp)
    For i = LBound(components) To ncomp
        moleFractions(i) = total / ncomp
    Next i
    
    Dim result As Variant
    result = conn.Functions.AverageMolecularWeight(components, moleFractions)
    Debug.Print ""
    Debug.Print String(110, "=")
    Debug.Print " Average Molecular Weight Tests"
    Debug.Print String(110, "=")
    Debug.Print "Component", "Mole Fraction", "MW"
    Logger.Log "Component, Mole Fraction, MW", LogHeader1
    
    If (IsNumeric(result)) Then
        Dim sum As Double
        sum = 0#
        Dim pureMW As Variant
        For i = LBound(moleFractions) To UBound(moleFractions)
            pureMW = conn.Functions.PureComponentConstant(components(i), par_MolecularWeight)
            Debug.Print components(i), moleFractions(i), pureMW
            Logger.Log "|> " & components(i) & ", " & moleFractions(i) & ", " & pureMW
            sum = sum + moleFractions(i)
        Next i
        Debug.Print String(110, "-")
        Debug.Print "Average MW", result
        Logger.LogLine "-"
        Logger.Log "Average MW = " & result
    Else ' error message
        Debug.Print "|> " & result
        Logger.Log "|> " & CStr(result)
    End If

End Sub

Private Sub UnitsConversionTests(Optional conn As VBConnection)

    ValidateConnection conn
    
    '==============================================================================================================
    ' UNITS CONVERSION TEST
    '==============================================================================================================
    
    Logger.Log "UNITS CONVERSION TEST", LogTitle
    
    Dim i As Integer
    Dim values(1 To 3) As Double
    values(1) = 32
    values(2) = 77
    values(3) = 100
    
    Dim result As Variant
    result = conn.Functions.UnitsConversion("F", "C", values) ' convert multiple values
    Debug.Print ""
    Debug.Print String(110, "=")
    Debug.Print " Units Conversion Test"
    Debug.Print String(110, "=")
    Debug.Print "Value", "From Unit", "To Unit", "Result"
    Logger.Log "Value, From Unit, To Unit, Result", LogHeader1
    
    For i = 1 To UBound(result)
        Debug.Print values(i), "F", "C", result(i)
        Logger.Log values(i) & ", F, C, " & result(i)
    Next i
    result = conn.Functions.UnitsConversion("F", "C", 212) ' convert singular value
    Debug.Print 212, "F", "C", result
    Logger.Log 212 & ", F, C, " & result
    Debug.Print String(110, "-")
    
End Sub

Private Sub MassFlowToMoleFractionTests(Optional conn As VBConnection)

    ValidateConnection conn
    
    Dim components As Variant
    Dim ncomp As Integer
    components = conn.Package.GetComponents
    ncomp = (UBound(components) - LBound(components)) + 1
    
    '==============================================================================================================
    ' MASS FLOWS TO MOLE FRACTIONS TEST
    '==============================================================================================================
    
    Logger.Log "MASS FLOWS TO MOLE FRACTIONS TEST", LogTitle
    
    Dim total As Double
    Dim massFlows As Variant
    Dim i As Integer
    total = 100#
    ReDim massFlows(1 To ncomp)
    For i = LBound(components) To ncomp
        massFlows(i) = total / ncomp
    Next i
    
    Dim result As Variant
    result = conn.Functions.MassFlowToMoleFraction(components, massFlows)

    Debug.Print ""
    Debug.Print String(110, "=")
    Debug.Print " Mass Flow to Mole Fraction Tests"
    Debug.Print String(110, "=")
    Debug.Print "Component", "Mass Flow", "Mole Fraction"
    Logger.Log "Component, Mass Flow, Mole Fraction", LogHeader1
    
    If (IsArray(result)) Then
        Dim sum As Double
        sum = 0#
        For i = LBound(result) To UBound(result)
            Debug.Print components(i), massFlows(i), result(i)
            Logger.Log "|> " & components(i) & ", " & massFlows(i) & ", " & result(i)
            sum = sum + result(i)
        Next i
        Debug.Print String(110, "-")
        Debug.Print "Total", total, sum
        Logger.LogLine "-"
        Logger.Log "Results sum = " & sum
    Else ' error message
        Debug.Print "|> " & result
        Logger.Log "|> " & CStr(result)
    End If
        
End Sub

Private Sub MassFractionToMoleFractionTests(Optional conn As VBConnection)

    ValidateConnection conn
    
    Dim components As Variant
    Dim ncomp As Integer
    components = conn.Package.GetComponents
    ncomp = (UBound(components) - LBound(components)) + 1
    
    '==============================================================================================================
    ' MASS FRACTIONS TO MOLE FRACTIONS TEST
    '==============================================================================================================
    
    Logger.Log "MASS FRACTION TO MOLE FRACTION TEST", LogTitle
    Dim total As Double
    Dim massFractions As Variant
    Dim i As Integer
    total = 1#
    ReDim massFractions(1 To ncomp)
    For i = LBound(components) To ncomp
        massFractions(i) = total / ncomp
    Next i
    
    Dim result As Variant
    result = conn.Functions.MassFractionToMoleFraction(components, massFractions)
    Debug.Print ""
    Debug.Print String(110, "=")
    Debug.Print " Mass Fraction to Mole Fraction Tests"
    Debug.Print String(110, "=")
    Debug.Print "Component", "Mass Fraction", "Mole Fraction"
    Logger.Log "Component, Mass Fraction, Mole Fraction", LogHeader1
    
    If (IsArray(result)) Then
        Dim sum As Double
        sum = 0#
        For i = LBound(result) To UBound(result)
            Debug.Print components(i), massFractions(i), result(i)
            Logger.Log "|> " & components(i) & ", " & massFractions(i) & ", " & result(i)
            sum = sum + result(i)
        Next i
        Debug.Print String(110, "-")
        Debug.Print "Total", total, sum
        Logger.LogLine "-"
        Logger.Log "Results sum = " & sum
    Else ' error message
        Debug.Print "|> " & result
        Logger.Log "|> " & CStr(result)
    End If

End Sub

Private Sub MoleFlowToMoleFractionTests(Optional conn As VBConnection)

    ValidateConnection conn
    
    Dim components As Variant
    Dim ncomp As Integer
    components = conn.Package.GetComponents
    ncomp = (UBound(components) - LBound(components)) + 1
    
    '==============================================================================================================
    ' MOLE FLOWS TO MOLE FRACTIONS TEST
    '==============================================================================================================
    
    Logger.Log "MOLE FLOWS TO MOLE FRACTIONS TEST", LogTitle
    
    Dim total As Double
    Dim moleFlows As Variant
    Dim i As Integer
    total = 100#
    ReDim moleFlows(1 To ncomp)
    For i = LBound(components) To ncomp
        moleFlows(i) = total / ncomp
    Next i
    
    Dim result As Variant
    result = conn.Functions.MoleFlowToMoleFraction(components, moleFlows)
    Debug.Print ""
    Debug.Print String(110, "=")
    Debug.Print " Mole Flow to Mole Fraction Tests"
    Debug.Print String(110, "=")
    Debug.Print "Component", "Mole Flow", "Mole Fraction"
    Logger.Log "Component, Mole Flow, Mole Fraction", LogHeader1
    
    If (IsArray(result)) Then
        Dim sum As Double
        sum = 0#
        For i = LBound(result) To UBound(result)
            Debug.Print components(i), moleFlows(i), result(i)
            Logger.Log "|> " & components(i) & ", " & moleFlows(i) & ", " & result(i)
            sum = sum + result(i)
        Next i
        Debug.Print String(110, "-")
        Debug.Print "Total", total, sum
        Logger.LogLine "-"
        Logger.Log "Results sum = " & sum
    Else ' error message
        Debug.Print "|> " & result
        Logger.Log "|> " & CStr(result)
    End If

End Sub

Private Sub MoleFractionToMassFractionTests(Optional conn As VBConnection)

    ValidateConnection conn
    
    Dim components As Variant
    Dim ncomp As Integer
    components = conn.Package.GetComponents
    ncomp = (UBound(components) - LBound(components)) + 1
    
    '==============================================================================================================
    ' MOLE FRACTIONS TO MASS FRACTIONS TEST
    '==============================================================================================================
    
    Logger.Log "MOLE FRACTIONS TO MASS FRACTIONS TEST", LogTitle
    
    Dim total As Double
    Dim moleFraction As Variant
    Dim i As Integer
    total = 1#
    ReDim moleFractions(1 To ncomp)
    For i = LBound(components) To ncomp
        moleFractions(i) = total / ncomp
    Next i
    
    Dim result As Variant
    result = conn.Functions.MoleFractionToMassFraction(components, moleFractions)
    Debug.Print ""
    Debug.Print String(110, "=")
    Debug.Print " Mole Fraction to Mass Fraction Tests"
    Debug.Print String(110, "=")
    Debug.Print "Component", "Mole Fraction", "Mass Fraction"
    Logger.Log "Component, Mole Fraction, Mass Fraction", LogHeader1
    
    If (IsArray(result)) Then
        Dim sum As Double
        sum = 0#
        For i = LBound(result) To UBound(result)
            Debug.Print components(i), moleFractions(i), result(i)
            Logger.Log "|> " & components(i) & ", " & moleFractions(i) & ", " & result(i)
            sum = sum + result(i)
        Next i
        Debug.Print String(110, "-")
        Debug.Print "Total", total, sum
        Logger.LogLine "-"
        Logger.Log "Results sum = " & sum
    Else ' error message
        Debug.Print "|> " & result
        Logger.Log "|> " & CStr(result)
    End If

End Sub

Private Sub PurePropertyTests(tt As Double, pp As Double, Optional conn As VBConnection)

    ValidateConnection conn ' creates connection or throws error if bad

    Dim components As Variant
    components = conn.Package.GetComponents
    
    '==============================================================================================================
    ' PURE PROPERTY TEST
    '==============================================================================================================
    Logger.Log "PURE PROPERTY TEST", LogTitle
    
    Dim results As Variant
    Dim i As Integer
    Dim j As Integer
    Dim k As Integer
    Dim codes() As Long
    Dim phase As String
    Dim phases As Variant
    
    phases = Array("V", "L", "S")
    
    codes = conn.Constants.PureProperty.GetValues
    For i = LBound(codes) To UBound(codes)
        For j = LBound(phases) To UBound(phases)
        
            results = conn.Functions.PureProperty(components, codes(i), tt, pp, phases(j))
            
            Debug.Print ""
            Debug.Print String(110, "=")
            Debug.Print conn.Helper.PropertyName(codes(i)) & "(T = " & tt & ", P = " & pp & ", phase = " & phases(j) & ")"
            Debug.Print conn.Helper.PropertyDescription(codes(i))
            Debug.Print String(110, "=")
            Debug.Print conn.Package.Name
            Debug.Print String(110, "-")
            Logger.Log conn.Helper.PropertyName(codes(i)) & "(T = " & tt & ", P = " & pp & ", phase = " & _
                phases(j) & ")" & VBA.vbCrLf & conn.Helper.PropertyDescription(codes(i)), LogHeader1
            Logger.Log "Package: " & conn.Package.Name
            Logger.LogLine "-"
            
            If (VarType(components) <> vbString) Then
                If (VarType(results) <> vbString) Then
                    For k = LBound(results) To UBound(results)
                        Debug.Print "|> " & components(k), results(k)
                        Logger.Log "|> " & components(k) & ", " & CStr(results(k))
                    Next k
                Else
                    For k = LBound(components) To UBound(components)
                        Debug.Print "|> " & components(k), results
                        Logger.Log "|> " & components(k) & ", " & results
                    Next k
                End If
            Else
                Debug.Print "|> " & components, results(1)
                Logger.Log "|> " & components & ", " & CStr(results(k))
            End If
        Next j
        DoEvents
    Next i
    Exit Sub

End Sub

Private Sub MixturePropertyTests(tt As Double, pp As Double, Optional conn As VBConnection)

    ValidateConnection conn ' creates connection or throws error if bad
    
    Dim components As Variant
    Dim ncomp As Integer
    components = conn.Package.GetComponents
    ncomp = (UBound(components) - LBound(components)) + 1
    
    Dim moleFractions As Variant
    Dim i As Integer
    ReDim moleFractions(1 To ncomp)
    For i = LBound(components) To ncomp
        moleFractions(i) = 1 / ncomp
    Next i
    
    '==============================================================================================================
    ' Mixture PROPERTY TEST
    '==============================================================================================================
    Logger.Log "MIXTURE PROPERTY TEST", LogTitle
    
    Dim result As Variant
    Dim j As Integer
    Dim k As Integer
    Dim codes() As Long
    Dim phases As Variant
    
    phases = Array("V", "L", "S")
    
    codes = conn.Constants.MixtureProperty.GetValues
    For i = 1 To UBound(codes)
    
        For j = 1 To UBound(phases)
    
            Debug.Print ""
            Debug.Print String(110, "=")
            Debug.Print conn.Helper.PropertyName(codes(i)) & "(T = " & tt & ", P = " & pp & ", phase = " & phases(j) & ")"
            Debug.Print conn.Helper.PropertyDescription(codes(i))
            Debug.Print String(110, "=")
            Debug.Print conn.Package.Name
            Debug.Print String(110, "-")
            Logger.Log conn.Helper.PropertyName(codes(i)) & "(T = " & tt & ", P = " & pp & ", phase = " & _
                phases(j) & ")" & VBA.vbCrLf & conn.Helper.PropertyDescription(codes(i)), LogHeader1
            Logger.Log "Package: " & conn.Package.Name
            Logger.LogLine "-"
        
            result = conn.Functions.MixtureProperty(components, moleFractions, codes(i), tt, pp, phases(j))
            
            If (IsArray(result)) Then
                For k = LBound(result) To UBound(result)
                    Debug.Print "|> " & components(k), result(k)
                    Logger.Log "|> " & components(k) & ", " & CStr(result(k))
                Next k
            Else
                Debug.Print "|> " & result
                Logger.Log "|> " & CStr(result)
            End If
        Next j
        DoEvents
    Next i
    Exit Sub

End Sub

Private Sub PureComponentConstantTest(Optional conn As VBConnection)

    ValidateConnection conn ' creates connection or throws error if bad
    
    Dim components As Variant
    components = conn.Package.GetComponents
    
    '==============================================================================================================
    ' PURE COMPONENT CONSTANT TEST
    '==============================================================================================================
    Logger.Log "PURE COMPONENT CONSTANT TEST", LogTitle
    
    Dim results As Variant
    Dim i As Integer
    Dim j As Integer
    Dim codes() As Long

    codes = conn.Constants.Parameter.GetValues
    
    For i = 1 To UBound(codes)
    
        Debug.Print ""
        Debug.Print String(110, "=")
        Debug.Print conn.Helper.PropertyName(codes(i))
        Debug.Print conn.Helper.PropertyDescription(codes(i))
        Debug.Print String(110, "=")
        Debug.Print conn.Package.Name
        Debug.Print String(110, "-")
        Logger.Log conn.Helper.PropertyName(codes(i)) & VBA.vbCrLf & conn.Helper.PropertyDescription(codes(i)), LogHeader1
        Logger.Log "Package: " & conn.Package.Name
        Logger.LogLine "-"
        
        results = conn.Functions.PureComponentConstant(components, codes(i))

        If (VarType(components) <> vbString) Then
            For j = LBound(results) To UBound(results)
                Debug.Print "|> " & components(j), results(j)
                Logger.Log "|> " & components(j) & ", " & CStr(results(j))
            Next j
        Else
            Debug.Print "|> " & components, results(1)
            Logger.Log "|> " & components(j) & ", " & results(1)
        End If
        DoEvents
    Next i
    Exit Sub
    
End Sub

Private Sub VaporPressureTest(tt As Double, Optional conn As VBConnection)

    ValidateConnection conn ' creates connection or throws error if bad

    Dim components As Variant
    components = conn.Package.GetComponents

    '==============================================================================================================
    ' VAPOR PRESSURE TEST
    '==============================================================================================================
    Logger.Log "VAPOR PRESSURE TEST", LogTitle
    
    Dim i As Integer
    Dim results As Variant
    
    Debug.Print ""
    Debug.Print String(110, "=")
    Debug.Print conn.Helper.PropertyName(conn.Constants.VaporPressure) & " (T = " & tt & ")"
    Debug.Print conn.Helper.PropertyDescription(AspenProperty.a_VaporPressure)
    Debug.Print String(110, "=")
    Debug.Print conn.Package.Name
    Debug.Print String(110, "-")
    Logger.Log conn.Helper.PropertyName(conn.Constants.VaporPressure) & " (T = " & tt & ")" & _
        VBA.vbCrLf & conn.Helper.PropertyDescription(AspenProperty.a_VaporPressure), LogHeader1
    Logger.Log "Package: " & conn.Package.Name
    Logger.LogLine "-"
        
    results = conn.Functions.VaporPressure(components, tt)
    
    If (VarType(components) <> vbString) Then
        If (VarType(results) <> vbString) Then
            For i = LBound(results) To UBound(results)
                Debug.Print "|> " & components(i), results(i)
                Logger.Log "|> " & components(i) & ", " & CStr(results(i))
            Next i
        Else
            For i = LBound(components) To UBound(components)
                Debug.Print "|> " & components(i), results
                Logger.Log "|> " & components(i) & ", " & results
            Next i
        End If
    Else
        Debug.Print "|> " & components, results(1)
        Logger.Log "|> " & components & ", " & CStr(results(1))
    End If
    Exit Sub
    
End Sub


Private Sub FlashPropertyTest(tt As Double, pp As Double, vfrac As Double, code As FlashType, Optional conn As VBConnection)

    ValidateConnection conn ' creates connection or throws error if bad
    
    Dim i As Integer
    Dim components As Variant
    Dim componentsToString As String
    components = conn.Package.GetComponents
    For i = 1 To UBound(components)
        If (i <> 1) Then
            componentsToString = componentsToString & ", (" & i & ") " & components(i)
        Else
            componentsToString = "(1) " & components(1)
        End If
    Next i
    
    Dim methods As Variant
    methods = conn.Package.GetMethods()
    
    Dim types As Variant
    types = conn.Constants.FLASH.GetValues
    
    Dim results As Variant
    Dim j As Integer
    Dim k As Integer
    Dim l As Integer
    Dim codes() As Long
    Dim moleFractions As Variant
    Dim ncomp As Integer
    
    ncomp = (UBound(components) - LBound(components)) + 1
    ReDim moleFractions(1 To ncomp)

    For i = LBound(components) To ncomp
        moleFractions(i) = 1 / ncomp
    Next i
    
    '==============================================================================================================
    ' FLASH TEST
    '==============================================================================================================
    Logger.Log "FLASH TEST", LogTitle
    
    Dim returns As Variant
    Dim flashKinds() As Long
    '--Dim code As Long
    flashKinds = conn.Constants.FLASH.GetValues
    
    Dim line As String
    Dim hh As Double ' enthalpy
    Dim ss As Double ' entropy
    Dim uu As Double ' internal energy
    Dim keyComponentLL As String
    
    hh = 0
    ss = 0
    uu = 0
    keyComponentLL = ""
    
    For i = 1 To UBound(flashKinds)
    
        returns = conn.Constants.ReturnWhat.GetValues(flashKinds(i))

        For j = 1 To UBound(methods)
        
            ss = conn.Functions.MixtureProperty(components, moleFractions, mix_Entropy, tt, pp, "L", methods(j))
            uu = conn.Functions.MixtureProperty(components, moleFractions, mix_InternalEnergy, tt, pp, "L", methods(j))
    
            Debug.Print ""
            Debug.Print String(110, "=")
            '--Debug.Print conn.Helper.FlashName(flashKinds(i)) & " (T = " & tt & ", P = " & pp & ", VF = " & vfrac & ")"
            code = flashKinds(i)
            If code = PH_LLE Or code = PH_VLE Or code = PH_VLLE Then
                line = conn.Helper.FlashName(flashKinds(i)) & " (P = " & pp & ", H = " & hh & "), " & conn.Helper.FlashDescription(flashKinds(i))
            ElseIf code = PS_VLE Then
                line = conn.Helper.FlashName(flashKinds(i)) & " (P = " & pp & ", S = " & ss & "), " & conn.Helper.FlashDescription(flashKinds(i))
            ElseIf code = PU_VLE Then
                line = conn.Helper.FlashName(flashKinds(i)) & " (P = " & pp & ", U = " & uu & "), " & conn.Helper.FlashDescription(flashKinds(i))
            ElseIf code = PV_VLE Or code = PV_VLLE Then
                line = conn.Helper.FlashName(flashKinds(i)) & " (P = " & pp & ", VFRAC = " & vfrac & "), " & conn.Helper.FlashDescription(flashKinds(i))
            ElseIf code = TH_LLE Or code = TH_VLE Or code = TH_VLLE Then
                line = conn.Helper.FlashName(flashKinds(i)) & " (T = " & tt & ", H = " & hh & "), " & conn.Helper.FlashDescription(flashKinds(i))
            ElseIf code = TP_LLE Or code = TP_VLE Or code = TP_VLLE Then
                line = conn.Helper.FlashName(flashKinds(i)) & " (T = " & tt & ", P = " & pp & "), " & conn.Helper.FlashDescription(flashKinds(i))
            ElseIf code = TV_VLE Or code = TV_VLLE Then
                line = conn.Helper.FlashName(flashKinds(i)) & " (T = " & tt & ", VFRAC = " & vfrac & "), " & conn.Helper.FlashDescription(flashKinds(i))
            Else
                MsgBox "Unknown flash type defined.", vbOKOnly + vbExclamation, "FlashPropertyTest"
                Exit Sub
            End If
            Debug.Print line
            Debug.Print String(110, "=")
            
            Debug.Print String(110, "-")
            Debug.Print "Package:    " & conn.Package.Name
            Debug.Print "Option set: " & methods(j)
            Debug.Print componentsToString
            Debug.Print String(110, "-")
            
            Logger.Log line, LogHeader1
            Logger.Log "Package: " & conn.Package.Name
            Logger.Log "Option set: " & methods(j)
            Logger.Log componentsToString
            Logger.LogLine "-"
            
            For k = 1 To UBound(returns)
                Select Case flashKinds(i)
                    Case FlashType.PH_LLE:
                        results = conn.Functions.PHFlashLL(components, moleFractions, pp, hh, returns(k), keyComponentLL, methods(j))
                    Case FlashType.PH_VLE:
                        results = conn.Functions.PHFlash(components, moleFractions, pp, hh, returns(k), methods(j))
                    Case FlashType.PH_VLLE:
                        results = conn.Functions.PHFlash3(components, moleFractions, pp, hh, returns(k), keyComponentLL, methods(j))
                    Case FlashType.PS_VLE:
                        results = conn.Functions.PSFlash(components, moleFractions, pp, ss, returns(k), methods(j))
                    Case FlashType.PU_VLE:
                        results = conn.Functions.PUFlash(components, moleFractions, pp, uu, returns(k), methods(j))
                    Case FlashType.PV_VLE:
                        results = conn.Functions.PVFlash(components, moleFractions, pp, vfrac, returns(k), methods(j))
                    Case FlashType.PV_VLLE:
                        results = conn.Functions.PVFlash3(components, moleFractions, pp, vfrac, returns(k), keyComponentLL, methods(j))
                    Case FlashType.TH_LLE:
                        results = conn.Functions.THFlashLL(components, moleFractions, tt, hh, returns(k), keyComponentLL, methods(j))
                    Case FlashType.TH_VLE:
                        results = conn.Functions.THFlash(components, moleFractions, tt, hh, returns(k), methods(j))
                    Case FlashType.TH_VLLE:
                        results = conn.Functions.THFlash3(components, moleFractions, tt, hh, returns(k), keyComponentLL, methods(j))
                    Case FlashType.TP_LLE:
                        results = conn.Functions.TPFlashLL(components, moleFractions, tt, pp, returns(k), keyComponentLL, methods(j))
                    Case FlashType.TP_VLE:
                        results = conn.Functions.TPFlash(components, moleFractions, tt, pp, returns(k), methods(j))
                    Case FlashType.TP_VLLE:
                        results = conn.Functions.TPFlash3(components, moleFractions, tt, pp, returns(k), keyComponentLL, methods(j))
                    Case FlashType.TV_VLE:
                        results = conn.Functions.TVFlash(components, moleFractions, tt, vfrac, returns(k), methods(j))
                        If (returns(k) = conn.Constants.ReturnWhat.TV.Enthalpy) Then
                            hh = results(1)
                        End If
                    Case FlashType.TV_VLLE:
                        results = conn.Functions.TVFlash3(components, moleFractions, tt, vfrac, returns(k), keyComponentLL, methods(j))
                    Case Else:
                        MsgBox "Unknown flash type defined.", vbOKOnly + vbExclamation, "FlashPropertyTest"
                End Select

                If (Not IsEmpty(results)) Then
                    If (returns(k) = out_X Or returns(k) = out_Y Or returns(k) = out_X1 Or returns(k) = OUT_X2) Then
                        Debug.Print "|> " & conn.Helper.ReturnName(CLng(returns(k)))
                        Logger.Log "|> " & conn.Helper.ReturnName(CLng(returns(k)))
                        For l = 1 To UBound(results)
                            Debug.Print "|--> " & conn.Helper.ReturnName(CLng(returns(k))) & "(" & l & ") = " & results(l)
                            Logger.Log "|--> " & conn.Helper.ReturnName(CLng(returns(k))) & "(" & l & ") = " & CStr(results(l))
                        Next l
                    Else ' singular result
                        Debug.Print "|> " & conn.Helper.ReturnName(CLng(returns(k))) & " = " & results(1)
                        Logger.Log "|> " & conn.Helper.ReturnName(CLng(returns(k))) & " = " & CStr(results(1))
                    End If
                Else
                    Debug.Print "|> " & conn.Helper.ReturnName(CLng(returns(j))) & " *** EMPTY ***"
                    Logger.Log "|> " & conn.Helper.ReturnName(CLng(returns(j))) & " *** EMPTY ***"
                End If
            Next k
        Next j
        DoEvents
    Next i
    Exit Sub
  
End Sub
