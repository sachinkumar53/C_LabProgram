#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,res;
    char op;
    printf("Enter two numbers:\n");
    scanf("%f%f",&a,&b);

    printf("Enter the operator:\n");
    scanf("%c",&op);
    scanf("%c",&op);

    switch (op)
    {
    case '+':
        res = a+b;
        break;
    
    case '-':
        res = a-b;
        break;
    
    case '*':
        res = a*b;
        break;
    
    case '/':
        if (b != 0)
        {
            res = a/b;    
        }else{
            printf("Division by zero is not possible.\n");
            exit(0);
        }
        break;
    
    case '%':
    if (b != 0)
        {
            res = (int)a % (int)b;
        }else{
            printf("Division by zero is not possible.\n");
            exit(0);
        }
        break;
    
    default:
        printf("Invalid operator.\n");
        break;

    }

    printf("Answer is %f\n",res);
    return 0;
}
