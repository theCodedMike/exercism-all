using System;
using System.Collections.Generic;

public class Authenticator
{
    // Implement the Authenticator.Admin property
    public Identity Admin { get; } = new()
    {
        Email = "admin@ex.ism",
        FacialFeatures = new FacialFeatures() { EyeColor = "green", PhiltrumWidth = 0.9m },
        NameAndAddress = ["Chanakya", "Mumbai", "India"]
    };

    // Implement the Authenticator.Developers property
    public IDictionary<string, Identity> Developers { get; } = new Dictionary<string, Identity>()
    {
        ["Bertrand"] = new()
        {
            Email = "bert@ex.ism",
            FacialFeatures = new FacialFeatures() { EyeColor = "blue", PhiltrumWidth = 0.8m },
            NameAndAddress = ["Bertrand", "Paris", "France"],
        },
        ["Anders"] = new()
        {
            Email = "anders@ex.ism",
            FacialFeatures = new FacialFeatures() { EyeColor = "brown", PhiltrumWidth = 0.85m },
            NameAndAddress = ["Anders", "Redmond", "USA"],
        }
    };
}

//**** please do not modify the FacialFeatures class ****
public class FacialFeatures
{
    public string EyeColor { get; set; }
    public decimal PhiltrumWidth { get; set; }
}

//**** please do not modify the Identity class ****
public class Identity
{
    public string Email { get; set; }
    public FacialFeatures FacialFeatures { get; set; }
    public IList<string> NameAndAddress { get; set; }
}