#include <stdio.h>

int main()
{
    int _num,num, digit[10], i,len,arm,flag;
    printf("Enter a number\n");
    scanf("%d",&num);

    _num = num;
    len = 0;
    i = 0;

    while (num != 0)
    {
        digit[i] = num%10;
        num = num/10; 
        i++;
    }

    len = i;
    arm = 0;
    for (i = 0; i < len; i++)
    {
        arm += (digit[i]*digit[i]*digit[i]);    
    }

    if (_num == arm)
    {
        printf("%d is an armstrong number.\n",_num);
    }else{
        printf("%d is not an armstrong number.\n",_num);
    }
    
    
    return 0;
}
