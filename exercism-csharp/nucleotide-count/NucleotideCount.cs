using System;
using System.Collections.Generic;
using System.Linq;

public static class NucleotideCount
{
    public static IDictionary<char, int> Count(string sequence)
    {
        IDictionary<char, int> map = new Dictionary<char, int>()
        {
            ['A'] = 0,
            ['T'] = 0,
            ['G'] = 0,
            ['C'] = 0,
        };
        
        /*
        sequence.Aggregate(map, (seed, ch) =>
        {
            switch (ch)
            {
                case 'A' or 'T' or 'G' or 'C':
                    seed[ch]++;
                    break;
                default: throw new ArgumentException();
            }

            return seed;
        });
        */

        foreach (var ch in sequence)
        {
            if (ch is 'A' or 'T' or 'G' or 'C')
                map[ch]++;
            else
                throw new ArgumentException();
            
        }

        return map;
    }
}