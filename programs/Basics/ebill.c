#include <stdio.h>

int main(){
    char name[20];
    int units;
    float amt, metercharge = 100.0;

    printf("Enter the customer name:\n");
    scanf("%s",name);

    printf("Enter the units consumed by the customer:\n");
    scanf("%d",&units);

    if (units < 0)
    {
        printf("Unit can not be negative.\n");
        return 0;
    }

    if(units >= 0 && units <= 200)
        amt = 100 + (units * 0.8);

    if(units > 200 && units <= 300)
        amt = 100 + (200*0.8) + (units-200) * 0.9;
    
    if (units > 300)
        amt = 100 + (200*0.8) + (100*0.9) + (units-300)*1.0;
    
    if(amt > 400)
        amt= amt + (amt*0.15);

    printf("Customer name: %s",name);   
    printf("\nUnits consumed: %d",units);   
    printf("\nTotal amount: %.2f",amt);   
    return 0;
}