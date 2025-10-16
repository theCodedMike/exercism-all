using System;

namespace BirdWatcher;

class BirdCount
{
    private int[] birdsPerDay;

    public BirdCount(int[] birdsPerDay)
    {
        this.birdsPerDay = birdsPerDay;
    }

    public static int[] LastWeek()
    {
        return [0, 2, 5, 3, 7, 8, 4];
    }

    public int Today()
    {
        return birdsPerDay[^1];
    }

    public void IncrementTodaysCount()
    {
        birdsPerDay[^1]++;
    }

    public bool HasDayWithoutBirds()
    {
        var hasDayWithoutBirds = false;
        foreach (var birds in birdsPerDay)
        {
            if (birds == 0)
            {
                hasDayWithoutBirds = true;
            }
        }

        return hasDayWithoutBirds;
    }

    public int CountForFirstDays(int numberOfDays)
    {
        var sum = 0;
        for (var i = 0; i < numberOfDays; i++)
        {
            sum += birdsPerDay[i];
        }

        return sum;
    }

    public int BusyDays()
    {
        var count = 0;
        foreach (var birds in birdsPerDay)
        {
            if (birds >= 5)
            {
                count++;
            }
        }

        return count;
    }
}
