#include <stdio.h>

struct student
{
    char name[20];
    int roll;
    float percentage;
};

void main()
{
    struct student s[10];
    int i,index;
    float max = 0.0f;

    for (i = 0; i < 5; i++)
    {
        printf("\nFor student %d:\n",i+1);
        printf("Enter name, roll no., percentage:\n");
        scanf("%s%d%f", s[i].name, &s[i].roll,&s[i].percentage);
    }
    
    
    for (i = 0; i < 5; i++){
        if (max < s[i].percentage ){
            max = s[i].percentage;
            index = i;
        }
    }

    printf("Highest percentage is %f%% obtained by %s", max,s[index].name);
}