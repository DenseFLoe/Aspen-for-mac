Attribute VB_Name = "RunAllExamples"


Option Explicit
Sub Main()
Attribute Main.VB_ProcData.VB_Invoke_Func = " \n14"
Dim ihAPsim As IHapp
Set ihAPsim = OpenSimulation()
Call GetCollectionExample(ihAPsim)
Call GetScalarValuesExample(ihAPsim)
Call ListBlocksExample(ihAPsim)
Call UnitStringExample(ihAPsim)
Call UnitsConversionExample(ihAPsim)
Call UnitsChangeExample(ihAPsim)
Call TempProfExample(ihAPsim)
Call CompProfExample(ihAPsim)
Call ReacCoeffExample(ihAPsim)
Call ConnectivityExample(ihAPsim)
Call RunExample(ihAPsim)
Call CloseSimulation(ihAPsim)
End Sub
