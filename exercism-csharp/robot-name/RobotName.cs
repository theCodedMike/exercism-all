using System;
using System.Collections.Generic;

public class Robot
{
    private static readonly HashSet<string> Names = [];
    private static readonly Random Random = new Random();

    private string? _name; // name

    public string Name => _name ??= GenName();


    public void Reset() => _name = null;

    private static string GenName()
    {
        string result;
        do
        {
            char firstIdx = (char)(Random.Next(0, 26) + 'A');
            char secondIdx = (char)(Random.Next(0, 26) + 'A');
            string threeDigits = Random.Next(0, 1000).ToString("000");
            result = "" + firstIdx + secondIdx + threeDigits;
        } while (Names.Contains(result));

        Names.Add(result);
        return result;
    }
}