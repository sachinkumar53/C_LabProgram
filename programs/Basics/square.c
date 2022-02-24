#include <stdio.h>

#define SQUARE(x) (x*x)
int main(){

    int x;
    printf("Enter a number:\n");
    scanf("%d",&x);

    printf("Square of %d is %d\n",x,SQUARE(x));

    return 0;
}