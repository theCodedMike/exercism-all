
public class SpaceAge(int seconds)
{
    private readonly double _seconds = seconds;
    
    private const double SecondsPerEarthYear = 31557600;
    private const double MercuryEarthRate = 0.2408467;
    private const double VenusEarthRate = 0.61519726;
    private const double MarsEarthRate = 1.8808158;
    private const double JupiterEarthRate = 11.862615;
    private const double SaturnEarthRate = 29.447498;
    private const double UranusEarthRate = 84.016846;
    private const double NeptuneEarthRate = 164.79132;
    
    public double OnEarth() => _seconds / SecondsPerEarthYear;
    public double OnMercury() => OnEarth() / MercuryEarthRate;
    public double OnVenus() => OnEarth() / VenusEarthRate;
    public double OnMars() => OnEarth() / MarsEarthRate;
    public double OnJupiter() => OnEarth() / JupiterEarthRate;
    public double OnSaturn() => OnEarth() / SaturnEarthRate;
    public double OnUranus() => OnEarth() / UranusEarthRate;
    public double OnNeptune() => OnEarth() / NeptuneEarthRate;
}