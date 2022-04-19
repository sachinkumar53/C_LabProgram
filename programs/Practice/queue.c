#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int q[MAX], f = 0, r = 0, count = 0;

void insert()
{
    if (count == MAX)
    {
        printf("Queue OVerflow\n");
        return;
    }

    int e;
    printf("Enter the element to insert: ");
    scanf("%d", &e);
    q[r] = e;
    r = (r + 1) % MAX;
    count++;
    printf("%d is inserted to queue\n",e);
}

void delete ()
{
    if (count <= 0)
    {
        printf("Queue Underflow\n");
        return;
    }

    int e;
    e = q[f];
    f = (f + 1) % MAX;
    printf("%d is deleted from queue\n", e);
    count--;
}

void display()
{
    if (count <= 0)
    {
        printf("Queue Underflow\n");
        return;
    }

    int j = f;
    for (int i = 0; i < count; i++)
    {
        printf("%d\t", q[j]);
        j=(j + 1) % MAX;
    }
    printf("\n");
}

void main()
{

    int ch;
    while (1)
    {
        printf("\nCircular Queue Menu\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert();
            break;

        case 2:
            delete ();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    }
}