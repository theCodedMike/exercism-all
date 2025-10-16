public static class ResistorColor
{
    private static readonly string[] Cols;

    static ResistorColor() =>
        Cols = [
            "black",
            "brown",
            "red",
            "orange",
            "yellow",
            "green",
            "blue",
            "violet",
            "grey",
            "white"
        ];

    public static int ColorCode(string color)
    {
        // return Array.IndexOf(Cols, color);
        for (int i = 0; i < Cols.Length; i++)
            if (Cols[i] == color)
                return i;

        return -1;
    }

    public static string[] Colors() => Cols;
}