using System;

// define the 'AccountType' enum
enum AccountType
{
    Guest,
    User,
    Moderator
}

// define the 'Permission' enum
[Flags]
enum Permission : byte
{
    Read = 1 << 0,
    Write = 1 << 1,
    Delete = 1 << 2,
    None = 0,
    All = Read | Write | Delete
}


static class Permissions
{
    public static Permission Default(AccountType accountType) => accountType switch
    {
        AccountType.Guest => Permission.Read,
        AccountType.User => Permission.Read | Permission.Write,
        AccountType.Moderator => Permission.All,
        _ => Permission.None
    };

    public static Permission Grant(Permission current, Permission grant) => current | grant;

    public static Permission Revoke(Permission current, Permission revoke) => current & ~revoke;

    public static bool Check(Permission current, Permission check) => current.HasFlag(check);
}