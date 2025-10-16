public class RemoteControlCar
{
    public RemoteControlCar()
    {
        Telemetry = new InnerTelemetry(this);
    }


    public string? CurrentSponsor { get; private set; }

    private Speed _currentSpeed;

    public readonly InnerTelemetry? Telemetry;

    public class InnerTelemetry(RemoteControlCar car)
    {
        public void Calibrate()
        {
        }

        public bool SelfTest()
        {
            return true;
        }

        public void ShowSponsor(string sponsorName)
        {
            car.SetSponsor(sponsorName);
        }

        public void SetSpeed(decimal amount, string unitsString)
        {
            var speedUnits = unitsString == "cps" ? SpeedUnits.CentimetersPerSecond : SpeedUnits.MetersPerSecond;

            car.SetSpeed(new Speed(amount, speedUnits));
        }
    }

    public string GetSpeed()
    {
        return _currentSpeed.ToString();
    }

    private void SetSponsor(string sponsorName)
    {
        CurrentSponsor = sponsorName;
    }

    private void SetSpeed(Speed speed)
    {
        _currentSpeed = speed;
    }
}

public enum SpeedUnits
{
    MetersPerSecond,
    CentimetersPerSecond
}

public struct Speed
{
    public decimal Amount { get; }
    public SpeedUnits SpeedUnits { get; }

    public Speed(decimal amount, SpeedUnits speedUnits)
    {
        Amount = amount;
        SpeedUnits = speedUnits;
    }

    public override string ToString()
    {
        return SpeedUnits == SpeedUnits.CentimetersPerSecond
            ? $"{Amount} centimeters per second"
            : $"{Amount} meters per second";
    }
}