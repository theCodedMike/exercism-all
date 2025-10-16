
class Lasagna
{
    // define the 'ExpectedMinutesInOven()' method
    public int ExpectedMinutesInOven()
    {
        return 40;
    }

    // define the 'RemainingMinutesInOven()' method
    public int RemainingMinutesInOven(int time)
    {
        return 40 - time;
    }

    // define the 'PreparationTimeInMinutes()' method
    public int PreparationTimeInMinutes(int pTime)
    {
        return 2 * pTime;
    }

    // define the 'ElapsedTimeInMinutes()' method
    public int ElapsedTimeInMinutes(int x, int y)
    {
        return x * 2 + y;
    }
}
