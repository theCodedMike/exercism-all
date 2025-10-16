using System;
using System.Text;

public static class Identifier
{
    public static string Clean(string identifier)
    {
        var sb = new StringBuilder(identifier.Length);
        var isDash = false;

        foreach (var ch in identifier.ToCharArray())
        {
            if (char.IsControl(ch))
            {
                sb.Append("CTRL");
            }
            else if (char.IsWhiteSpace(ch))
            {
                sb.Append('_');
            }
            else if (ch.Equals('-'))
            {
                isDash = true;
            }
            else if (!char.IsLetter(ch) || IsGreekLowerCaseLetter(ch))
            {
                // continue
            }
            else
            {
                if (isDash)
                {
                    sb.Append(char.ToUpperInvariant(ch));
                    isDash = false;
                }
                else
                {
                    sb.Append(ch);
                }
            }
        }

        return sb.ToString();
    }

    private static bool IsGreekLowerCaseLetter(char ch)
    {
        return ch is >= 'α' and <= 'ω';
    }
}