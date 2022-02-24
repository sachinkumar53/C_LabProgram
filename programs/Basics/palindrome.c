#include <stdio.h>

int main(){
    int num,digit,rev = 0,a;

    printf("Enter a positive number\n");
    scanf("%d",&num);
    
    a = num;

    while (num != 0)
    {
        digit = num%10;
        num = num/10;
        rev = (rev * 10) + digit;
    }

    printf("Reverse of %d is %d\n",a,rev);
    
    if (a == rev)
        printf("It is a palindrome number.\n");
    else 
        printf("It is not a palindrome number.\n");
    
    return 0;
}