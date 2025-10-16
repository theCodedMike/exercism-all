using System;

public static class CentralBank
{
    private const string TooBig = "*** Too Big ***";
    private const string MuchTooBig = "*** Much Too Big ***";
    
    public static string DisplayDenomination(long @base, long multiplier)
    {
        try
        {
            return checked(@base * multiplier).ToString();
        }
        catch (OverflowException)
        {
            return TooBig;
        }
    }

    public static string DisplayGDP(float @base, float multiplier)
    {

        double gdp = @base * multiplier;
        return double.IsInfinity(gdp) ? TooBig : gdp.ToString();
    }

    public static string DisplayChiefEconomistSalary(decimal salaryBase, decimal multiplier)
    {
        try
        {
            return checked(salaryBase * multiplier).ToString();
        }
        catch (OverflowException)
        {
            return MuchTooBig;
        }
    }
}
