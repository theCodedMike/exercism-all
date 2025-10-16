using System;

public class CalculationException : Exception
{
    public CalculationException() : base() {}
    public CalculationException(string message) : base(message) {}
    public CalculationException(string message, Exception innerException) : base(message, innerException) {}
    // complete the definition of the constructor
    public CalculationException(int operand1, int operand2, string message, Exception inner) : base(message, inner)
    {
        Operand1 = operand1;
        Operand2 = operand2;
    }
    
    public int Operand1 { get; }
    public int Operand2 { get; }
}

public class CalculatorTestHarness
{
    private Calculator calculator;

    public CalculatorTestHarness(Calculator calculator)
    {
        this.calculator = calculator;
    }

    public string TestMultiplication(int x, int y)
    {
        try
        {
            Multiply(x, y);
        }
        catch (CalculationException e) when (e.Operand1 <= 0 && e.Operand2 <= 0)
        {
            return $"Multiply failed for negative operands. {e.Message}";
        }
        catch (CalculationException e) when (e.Operand1 >= 0 || e.Operand2 >= 0)
        {
            return $"Multiply failed for mixed or positive operands. {e.Message}";
        }

        return "Multiply succeeded";
    }

    public void Multiply(int x, int y)
    {
        try
        {
            calculator.Multiply(x, y);
        }
        catch (OverflowException e) 
        {
            throw new CalculationException(x, y, "Arithmetic operation resulted in an overflow.", e);
        }
    }
}


// Please do not modify the code below.
// If there is an overflow in the multiplication operation
// then a System.OverflowException is thrown.
public class Calculator
{
    public int Multiply(int x, int y)
    {
        checked
        {
            return x * y;
        }
    }
}
