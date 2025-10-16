using System;
using System.ComponentModel;
using System.Globalization;


public enum Location
{
    NewYork,
    London,
    Paris
}

public enum AlertLevel
{
    Early,
    Standard,
    Late
}

public static class Appointment
{
    public static DateTime ShowLocalTime(DateTime dtUtc) => dtUtc.ToLocalTime();

    public static DateTime Schedule(string appointmentDateDescription, Location location) =>
        TimeZoneInfo.ConvertTimeToUtc(DateTime.Parse(appointmentDateDescription), GetTimeZoneInfo(location));

    public static DateTime GetAlertTime(DateTime appointment, AlertLevel alertLevel) => alertLevel switch
    {
        AlertLevel.Early => appointment.AddDays(-1),
        AlertLevel.Standard => appointment.AddMinutes(-105),
        AlertLevel.Late => appointment.AddMinutes(-30),
        _ => throw new ArgumentOutOfRangeException(nameof(alertLevel), alertLevel, null)
    };

    public static bool HasDaylightSavingChanged(DateTime dt, Location location)
    {
        var tzInfo = GetTimeZoneInfo(location);
        var isDaylightSavingTime = tzInfo.IsDaylightSavingTime(dt);
        var wasDaylightSavingTime = tzInfo.IsDaylightSavingTime(dt.AddDays(-7));
        return isDaylightSavingTime != wasDaylightSavingTime;
    }

    public static DateTime NormalizeDateTime(string dtStr, Location location)
    {
        if (DateTime.TryParse(dtStr, GetCultureInfo(location), DateTimeStyles.None, out var dt))
            return dt;
        
        return new DateTime(1, 1, 1);
    }

    private static TimeZoneInfo GetTimeZoneInfo(Location location) => OperatingSystem.IsWindows()
        ? WindowsTimeZoneInfo(location)
        : UnixTimeZoneInfo(location);

    private static TimeZoneInfo WindowsTimeZoneInfo(Location location) => location switch
    {
        Location.NewYork => TimeZoneInfo.FindSystemTimeZoneById("Eastern Standard Time"),
        Location.London => TimeZoneInfo.FindSystemTimeZoneById("GMT Standard Time"),
        Location.Paris => TimeZoneInfo.FindSystemTimeZoneById("W. Europe Standard Time"),
        _ => throw new ArgumentOutOfRangeException(nameof(location), location, null)
    };
    
    private static TimeZoneInfo UnixTimeZoneInfo(Location location) => location switch
    {
        Location.NewYork => TimeZoneInfo.FindSystemTimeZoneById("America/New_York"),
        Location.London => TimeZoneInfo.FindSystemTimeZoneById("Europe/London"),
        Location.Paris => TimeZoneInfo.FindSystemTimeZoneById("Europe/Paris"),
        _ => throw new ArgumentOutOfRangeException(nameof(location), location, null)
    };
    
    private static CultureInfo GetCultureInfo(Location location) => location switch
    {
        Location.NewYork => CultureInfo.GetCultureInfo("en-US"),
        Location.London => CultureInfo.GetCultureInfo("en-GB"),
        Location.Paris => CultureInfo.GetCultureInfo("fr-FR"),
        _ => throw new ArgumentOutOfRangeException(nameof(location), location, null)
    };
}
