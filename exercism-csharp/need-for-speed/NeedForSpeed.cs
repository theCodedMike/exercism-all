using System;

class RemoteControlCar
{
    public int Speed { get; } // 速度
    public int BatteryDrain { get; } // 每次行驶消耗的电量
    private int _distance; // 行驶的总距离
    private int _battery = 100; // 剩余电量

    // define the constructor for the 'RemoteControlCar' class
    public RemoteControlCar(int speed, int batteryDrain)
    {
        Speed = speed;
        BatteryDrain = batteryDrain;
    }

    public bool BatteryDrained()
    {
        return _battery < BatteryDrain;
    }

    public int DistanceDriven()
    {
        return _distance;
    }

    public void Drive()
    {
        if (_battery == 0) return;
        if (_battery >= BatteryDrain)
        {
            _distance += Speed;
            _battery -= BatteryDrain;
        }
        else
        {
            _battery = 0;
        }
    }

    public static RemoteControlCar Nitro()
    {
        return new RemoteControlCar(50, 4);
    }
}

class RaceTrack
{
    private readonly int _distance;

    // define the constructor for the 'RaceTrack' class
    public RaceTrack(int distance)
    {
        _distance = distance;
    }

    public bool TryFinishTrack(RemoteControlCar car)
    {
        return 100.0 / car.BatteryDrain * car.Speed >= _distance;
    }
}