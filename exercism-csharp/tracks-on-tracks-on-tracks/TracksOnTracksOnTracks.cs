using System;
using System.Collections.Generic;
using System.Linq;

public static class Languages
{
    public static List<string> NewList() => [];

    public static List<string> GetExistingLanguages() => ["C#", "Clojure", "Elm"];

    public static List<string> AddLanguage(List<string> languages, string language)
    {
        languages.Add(language);
        return languages;
    }

    public static int CountLanguages(List<string> languages) => languages.Count;

    public static bool HasLanguage(List<string> languages, string language) => languages.Contains(language);

    public static List<string> ReverseList(List<string> languages)
    {
        languages.Reverse();
        return languages;
    }

    public static bool IsExciting(List<string> languages)
    {
        bool IsEmpty(List<string> list) => list.Count == 0;

        if (IsEmpty(languages)) return false;

        const string cSharp = "C#";
        return languages[0] == cSharp || (languages[1] == cSharp && languages.Count is 2 or 3);
    }

    public static List<string> RemoveLanguage(List<string> languages, string language)
    {
        languages.Remove(language);
        return languages;
    }

    public static bool IsUnique(List<string> languages) => languages.ToHashSet().Count == languages.Count;
}