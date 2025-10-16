using System;
using System.Globalization;

public static class HighSchoolSweethearts
{
    private const int SingleLineMaxLen = 61;
    private const string Heart = " ♡ ";

    private const string ArtHeart =
        @"
     ******       ******
   **      **   **      **
 **         ** **         **
**            *            **
**                         **
**     {0}  +  {1}     **
 **                       **
   **                   **
     **               **
       **           **
         **       **
           **   **
             ***
              *
";

    private static readonly int PadTotalLen;

    static HighSchoolSweethearts()
    {
        PadTotalLen = (SingleLineMaxLen - Heart.Length) / 2;
    }

    public static string DisplaySingleLine(string studentA, string studentB) =>
        studentA.PadLeft(PadTotalLen) + Heart + studentB.PadRight(PadTotalLen);


    public static string DisplayBanner(string studentA, string studentB) =>
        string.Format(null, ArtHeart, studentA.Trim(), studentB.Trim());

    public static string DisplayGermanExchangeStudents(string studentA
        , string studentB, DateTime start, float hours)
        => string.Format(new CultureInfo("de-DE"), "{0} and {1} have been dating since {2:d} - that's {3:n2} hours",
            studentA, studentB, start, hours);
}