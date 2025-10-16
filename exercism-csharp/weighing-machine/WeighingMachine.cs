using System;

class WeighingMachine
{
    // define the 'Precision' property
    public int Precision { get;}

    // define the 'Weight' property
    private double _weight;
    
    // define the 'DisplayWeight' property
    public string DisplayWeight => $"{(_weight - TareAdjustment).ToString($"F{Precision}")} kg";
    
    // define the 'TareAdjustment' property
    public double TareAdjustment { get; set; } = 5;
    
    public double Weight
    {
        get => _weight;
        set
        {
            if (value < 0)
                throw new ArgumentOutOfRangeException();
            _weight = value;
        }
    }

    public WeighingMachine(int precision) => Precision = precision;
    
}
