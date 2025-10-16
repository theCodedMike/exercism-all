using System;
using System.Linq;
using System.Text.RegularExpressions;

public class LogParser
{
    private readonly Regex _splitRegex = new(@"<\^{0,}\*{0,}={0,}-{0,}>");
    private readonly Regex _countRegex = new("\".{0,}password.{0,}\"", RegexOptions.IgnoreCase);
    private readonly Regex _removeRegex = new(@"end-of-line\d{0,}");
    private readonly Regex _containsRegex = new(@"password\w{1,}", RegexOptions.IgnoreCase);

    public bool IsValidLine(string text) => text[0..5] switch
    {
        "[TRC]" or "[DBG]" or "[INF]" or "[WRN]" or "[ERR]" or "[FTL]" => true,
        _ => false,
    };

    public string[] SplitLogLine(string text) => _splitRegex.Split(text);

    public int CountQuotedPasswords(string lines) => _countRegex.Count(lines);

    public string RemoveEndOfLineText(string line) => _removeRegex.Replace(line, string.Empty);

    public string[] ListLinesWithPasswords(string[] lines) =>
        lines.Select(line =>
        {
            var matches = _containsRegex.Matches(line);
            return (matches.Count == 0 ? "--------" : matches[0].Value) + ": " + line;
        }).ToArray();
}