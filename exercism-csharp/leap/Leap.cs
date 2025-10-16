using System;

public static class Leap
{
    public static bool IsLeapYear(int year)
        //=> year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
        //=> year % 100 == 0 ? year % 400 == 0 : year % 4 == 0;
        //=> DateTime.IsLeapYear(year);
        => (year % 4 == 0, year % 100 == 0, year % 400 == 0) switch
        {
            (true, false, _) => true,
            (_, true, true) => true,
            _ => false,
        };
}