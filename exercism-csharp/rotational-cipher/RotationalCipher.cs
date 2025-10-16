using System;
using System.Text;
using System.Linq;

public static class RotationalCipher
{
    public static string Rotate(string text, int shiftKey)
    {
        return text.Aggregate(new StringBuilder(text.Length), (acc, ch) =>
        {
            var temp = ch switch
            {
                _ when char.IsAsciiLetterLower(ch) => HandleLetter(ch, 'a'),
                _ when char.IsAsciiLetterUpper(ch) => HandleLetter(ch, 'A'),
                _ => ch,
            };

            acc.Append(temp);
            return acc;
        }).ToString();
        
        char HandleLetter(char ch, char start) => (char)(start + (ch - start + shiftKey) % 26);
    }
}