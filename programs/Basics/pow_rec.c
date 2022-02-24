#include <stdio.h>

int power(int,int);
int main()
{
    int a = 4, p = 3,r;
    r = power(a,p);

    printf("Result is %d\n",r);
    return 0;
}

int power(int a,int n){
    if (n == 0)
    {
        return 1;
    }else if (n == 1)
    {
        return a;
    }else{
        return a*power(a,n-1);
    }    
}
