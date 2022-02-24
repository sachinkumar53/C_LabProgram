#include <stdio.h>

int gcd(int,int);

int main()
{
    int x, y,res;

    printf("Enter two numbers\n");
    scanf("%d%d", &x, &y);
    res = gcd(x,y);

    printf("GCD is %d\n",res);
    return 0;
}

int gcd(int x, int y)
{
    if (x == y)
    {
        return x;
    }
    else if (x < y)
    {
        y = y - x;
        gcd(x, y);
    }
    else
    {
        x = x - y;
        gcd(y, x);
    }
}