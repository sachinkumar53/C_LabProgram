#include <stdio.h>

int is_prime(int);

int main()
{
    int num;
    printf("Enter a number:\n");
    scanf("%d",&num);

    if (num < 0 || num == 1)
    {
        printf("Prime number doesn't exist.\n");
        return 0;
    }
    

    if (is_prime(num))
        printf("%d is a prime number.\n",num);
    else
        printf("%d is not a prime number.\n",num);
        
    return 0;
}

int is_prime(int n){
    for (int i = 2; i <= n/2; i++)
    {
        if (n%i == 0)
        {
            return 0;
        }
        
    }
    
    return 1;
}
