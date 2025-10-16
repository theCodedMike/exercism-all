using System;
using System.Linq;

public static class Hamming
{
    public static int Distance(string firstStrand, string secondStrand)
    {
        if (firstStrand.Length != secondStrand.Length)
            throw new ArgumentException();

        /*
        int distance = 0;
        for (int i = 0, len = firstStrand.Length; i < len; i++)
            if (firstStrand[i] != secondStrand[i])
                distance++;

        return distance;
        */

        return firstStrand.Zip(secondStrand).Count(pair => pair.First != pair.Second);
    }
}