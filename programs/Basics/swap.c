#include <stdio.h>

void swap(int*,int*);

int main()
{
    int a = 5, b = 3;
    
    printf("Before swapping: a=%d\tb=%d\n",a,b);
    swap(&a,&b);
    printf("After swapping: a=%d\tb=%d\n",a,b);
    return 0;
}


void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

