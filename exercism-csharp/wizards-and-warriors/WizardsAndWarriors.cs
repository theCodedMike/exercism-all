using System;

abstract class Character
{
    private string CharacterType => GetType().Name;

    public abstract int DamagePoints(Character target);

    public virtual bool Vulnerable() => false;

    public override string ToString() => $"Character is a {CharacterType}";
}

class Warrior : Character
{
    public override int DamagePoints(Character target) => target.Vulnerable() ? 10 : 6;
}

class Wizard : Character
{
    private int _spell;

    public override bool Vulnerable() => _spell == 0;

    public override int DamagePoints(Character target) => Vulnerable() ? 3 : 12;

    public void PrepareSpell()
    {
        _spell++;
    }
}
