using System;

public static class SimpleCalculator
{
    public static string Calculate(int operand1, int operand2, string operation) => operation switch
    {
        null => throw new ArgumentNullException(),
        "" => throw new ArgumentException(),
        Operation.Division when operand2 == 0 => "Division by zero is not allowed.",
        Operation.Addition or Operation.Multiplication or Operation.Division =>
            $"{operand1} {operation} {operand2} = {Calc(operand1, operand2, operation)}",
        _ => throw new ArgumentOutOfRangeException(),
    };

    private static int Calc(int operand1, int operand2, string operation) => operation switch
    {
        Operation.Addition => operand1 + operand2,
        Operation.Multiplication => operand1 * operand2,
        Operation.Division => operand1 / operand2,
        _ => 0
    };
}

static class Operation
{
    public const string Addition = "+";
    public const string Multiplication = "*";
    public const string Division = "/";
}