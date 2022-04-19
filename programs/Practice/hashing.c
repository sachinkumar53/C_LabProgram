#include <stdio.h>
#define MAX 100

struct emp
{
    int id;
    char name[20];
};

typedef struct emp EMP;
EMP emp[MAX];
int a[MAX];

int create(int empid)
{
    return empid % MAX;
}

void linear_prob(int key, int empid)
{
    if (a[key] == -1)
    {
        a[key] = key;
        printf("Enter employee name\n");
        scanf("%s", emp[key].name);
        emp[key].id = empid;
    }
    else
    {
        int i, flag = 0, pos;
        printf("Collision occured resolved using linear probing\n");
        for (i = key; i < MAX; i++)
        {
            if (a[i] == -1)
            {
                flag = 1;
                pos = i;
                break;
            }
        }

        if (flag == 0)
        {
            for (i = 0; i < key; i++)
            {
                if (a[i] == -1)
                {
                    flag = 1;
                    pos = i;
                    break;
                }
            }
        }

        if (flag)
        {
            a[pos] = key;
            printf("Enter employee name\n");
            scanf("%s", emp[key].name);
            emp[pos].id = empid;
        }
        else
        {
            printf("Hash table Overflow\n");
        }
    }
}

void display()
{
    int ch, i;
    printf("\n1. Display All\n2. Filtered display\n");
    printf("Enter the choice\n");
    scanf("%d", &ch);
    if (ch == 1)
    {
        printf("\nLOC\tEMP ID\tEMP Name\n");
        for (i = 0; i < MAX; i++)
        {
            printf("%d\t%d\t%s\n", i, emp[i].id, emp[i].name);
        }
    }
    else
    {
        printf("\nLOC\tEMP ID\tEMP Name\n");
        for (i = 0; i < MAX; i++)
        {
            if (a[i] != -1)
                printf("%d\t%d\t%s\n", i, emp[i].id, emp[i].name);
        }
    }
}

void main()
{

    int i, key,empid,ans;
    for (i = 0; i < MAX; i++)
        a[i] = -1;
    

    printf("\nHASH TABLE MENU\n");
    do
    {
        printf("Enter the 4 digit emp id\n");
        scanf("%d",&empid);
        key = create(empid);
        linear_prob(key,empid);
        printf("Do you wish to contine?(1/0): ");
        scanf("%d",&ans);
    } while (ans);

    display();
    
}