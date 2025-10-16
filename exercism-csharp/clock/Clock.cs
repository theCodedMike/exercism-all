using System;

public class Clock
{
    private const int MinutesPerDay = 24 * 60;
    private readonly int _hours;
    private readonly int _minutes;

    public Clock(int hours, int minutes)
    {
        int totalMinutes = (hours * 60 + minutes) % MinutesPerDay;
        while (totalMinutes < 0)
            totalMinutes += MinutesPerDay;
        
        _hours = totalMinutes / 60;
        _minutes = totalMinutes % 60;
    }

    public Clock Add(int minutesToAdd) => new(_hours, _minutes + minutesToAdd);

    public Clock Subtract(int minutesToSubtract) => new(_hours, _minutes - minutesToSubtract);

    public override string ToString() => string.Format(null, "{0:D2}:{1:D2}", _hours, _minutes);

    public override int GetHashCode() => HashCode.Combine(_hours, _minutes);
    
    public override bool Equals(object? obj) => Equals(obj as Clock);
    
    private bool Equals(Clock? other) => other != null && _hours == other._hours && _minutes == other._minutes;
}