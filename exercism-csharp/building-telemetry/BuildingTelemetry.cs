using System;

public class RemoteControlCar
{
    private int _batteryPercentage = 100;
    private int _distanceDrivenInMeters = 0;
    private string[] _sponsors = new string[0];
    private int _latestSerialNum = 0;

    public void Drive()
    {
        if (_batteryPercentage <= 0) return;

        _batteryPercentage -= 10;
        _distanceDrivenInMeters += 2;
    }

    public void SetSponsors(params string[] sponsors) => this._sponsors = sponsors;

    public string DisplaySponsor(int sponsorNum) => _sponsors[sponsorNum];

    public bool GetTelemetryData(ref int serialNum, out int batteryPercentage, out int distanceDrivenInMeters)
    {
        if (serialNum < _latestSerialNum)
        {
            (serialNum, batteryPercentage, distanceDrivenInMeters) = (_latestSerialNum, -1, -1);
            return false;
        }

        (_latestSerialNum, batteryPercentage, distanceDrivenInMeters) =
            (serialNum, _batteryPercentage, _distanceDrivenInMeters);
        return true;
    }

    public static RemoteControlCar Buy() => new();
}

public class TelemetryClient(RemoteControlCar car)
{
    public string GetBatteryUsagePerMeter(int serialNum) =>
        (car.GetTelemetryData(ref serialNum, out int battery, out int distance) && distance > 0)
            ? $"usage-per-meter={(100 - battery) / distance}"
            : "no data";
}