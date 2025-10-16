using System;

class RemoteControlCar
{
    private uint _distance;
    private ushort _battery = 100;
    
    public static RemoteControlCar Buy()
    {
        return new RemoteControlCar();
    }

    public string DistanceDisplay()
    {
        return $"Driven {_distance} meters";
    }

    public string BatteryDisplay()
    {
        return _battery == 0 ? "Battery empty" : $"Battery at {_battery}%";
    }

    public void Drive()
    {
        if (_battery == 0) return;
        _battery--;
        _distance += 20;
    }
}
