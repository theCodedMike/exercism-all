using Xunit;

public class HelloWorldTests
{
    [Fact]
    public void Say_hi_()
    {
        Assert.Equal((string)"Hello, World!", HelloWorld.HelloWorld.Hello());
    }
}