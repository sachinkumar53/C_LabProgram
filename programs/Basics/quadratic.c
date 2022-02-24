#include <stdio.h>
#include <math.h>

int main(){
    float a,b,c,d,r1,r2,real,img;

    printf("Enter coeffecients of quadratic equation\n");
    scanf("%f%f%f",&a,&b,&c);

    if (a == 0)
    {
        printf("Invalid input. Can't determine roots\n");
    }else{
        d = (b*b) - (4*a*c);

        if (d > 0)
        {
            printf("Roots are real and distinct.\n");
            r1 = ((-b) + sqrt(d))/(2*a);
            r2 = ((-b) - sqrt(d))/(2*a);
            printf("Root1 : %f\n",r1);
            printf("Root2 : %f\n",r2);
        }else if ( d == 0)
        {
            printf("Roots are real and equal.\n");
            r1 = (-b) /(2*a);
            r2 = r1;
            printf("Root1 : %f\n",r1);
            printf("Root2 : %f\n",r2);
        }else{
            printf("Roots are imaginary.\n");
            real = (-b) /(2*a);
            img = sqrt(fabs(d))/(2*a);
            printf("Root1 : %f + i%f\n",real,img);
            printf("Root2 : %f - i%f\n",real,img); 
        }
        
        return 0;
    }
    
    return 0;
}