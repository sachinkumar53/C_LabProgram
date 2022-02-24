#include <stdio.h>

struct student
{
    char name[20];
    char usn[10];
    float marks;
};

int main()
{

    struct student s[10];
    int i;

    for (i = 0; i < 10; i++)
    {
        printf("Enter student name:\n");
        scanf("%s", s[i].name);

        printf("Enter student usn:\n");
        scanf("%s", s[i].usn);

        printf("Enter student marks:\n");
        scanf("%f", &s[i].marks);
    }

    printf("\n_________Student Details________\n");
    
    for (i = 0; i < 10; i++)
    {
        printf("\nName:\t%s", s[i].name);
        printf("\nUSN:\t%s", s[i].usn);
        printf("\nMarks:\t%f", s[i].marks);
    }

    return 0;
}