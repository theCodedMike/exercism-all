using System;

static class AssemblyLine
{
    private const int ProductionSpeedPerHour = 221;
    
    public static double SuccessRate(int speed) => speed switch
    {
        0 => 0,
        <= 4 => 1,
        <= 8 => 0.9,
        9 => 0.8,
        10 => 0.77,
        _ => double.NaN
        
    };

    public static double ProductionRatePerHour(int speed) => speed * ProductionSpeedPerHour * SuccessRate(speed);

    public static int WorkingItemsPerMinute(int speed) => (int)(ProductionRatePerHour(speed) / 60);
}
