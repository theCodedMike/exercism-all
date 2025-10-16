using System;
using System.Collections.Generic;
using System.Linq;

public record struct Coord
{
    public Coord(ushort x, ushort y)
    {
        X = x;
        Y = y;
    }

    public ushort X { get; }
    public ushort Y { get; }

    public double CalcDistance(Coord other) => Math.Pow(X - other.X, 2) + Math.Pow(Y - other.Y, 2);
}

public record struct Plot
{
    // Complete implementation of the Plot struct
    public Coord Coord1 { get; }
    public Coord Coord2 { get; }
    public Coord Coord3 { get; }
    public Coord Coord4 { get; }
    public double LongestDistance { get; }

    public Plot(Coord coord1, Coord coord2, Coord coord3, Coord coord4)
    {
        (Coord1, Coord2, Coord3, Coord4) = (coord1, coord2, coord3, coord4);
        
        double[] distances =
        [
            Coord1.CalcDistance(Coord2),
            Coord2.CalcDistance(Coord3),
            Coord3.CalcDistance(Coord4),
            Coord4.CalcDistance(Coord1),
        ];
        
        LongestDistance = distances.Max();
    }
}


public class ClaimsHandler
{
    private readonly List<Plot> _plots = [];
    
    public void StakeClaim(Plot plot)
    {
        if (!IsClaimStaked(plot))
            _plots.Add(plot);
    }

    public bool IsClaimStaked(Plot plot) => _plots.Contains(plot);

    public bool IsLastClaim(Plot plot) => plot.Equals(_plots.Last());

    public Plot GetClaimWithLongestSide() => _plots.OrderByDescending( p => p.LongestDistance).First();
}
