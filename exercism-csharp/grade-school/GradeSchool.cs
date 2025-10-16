using System;
using System.Collections.Generic;
using System.Linq;

public class GradeSchool
{
    private readonly SortedDictionary<string, int> _students = [];

    public bool Add(string student, int grade) => _students.TryAdd(student, grade);

    public IEnumerable<string> Roster() => _students.OrderBy(kv => kv.Value).Select(kv => kv.Key);

    public IEnumerable<string> Grade(int grade) => _students.Where(kv => kv.Value == grade).Select(kv => kv.Key);
}