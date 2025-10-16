using System;

public static class LogAnalysis 
{
    // define the 'SubstringAfter()' extension method on the `string` type
    public static string SubstringAfter(this string str, string delimiter) =>
        str[(str.IndexOf(delimiter, StringComparison.Ordinal) + delimiter.Length)..];

    // define the 'SubstringBetween()' extension method on the `string` type
    public static string SubstringBetween(this string str, string start, string end) => str[
        (str.IndexOf(start, StringComparison.Ordinal) + start.Length)..str.IndexOf(end, StringComparison.Ordinal)];

    // define the 'Message()' extension method on the `string` type
    public static string Message(this string str) => str.SubstringAfter(": ");

    // define the 'LogLevel()' extension method on the `string` type
    public static string LogLevel(this string str) => str.SubstringBetween("[", "]");
}