using System;

static class Appointment
{
    public static DateTime Schedule(string appointmentDateDescription)
    {
        return DateTime.Parse(appointmentDateDescription);
    }

    public static bool HasPassed(DateTime appointmentDate)
    {
        return DateTime.Now > appointmentDate;
    }

    public static bool IsAfternoonAppointment(DateTime appointmentDate)
    {
        return appointmentDate.Hour is >= 12 and < 18;
    }

    public static string Description(DateTime appointmentDate)
    {
        return $"You have an appointment on {appointmentDate}.";
    }

    public static DateTime AnniversaryDate()
    {
        return new DateTime(DateTime.Now.Year, 9, 15);
    }
}
