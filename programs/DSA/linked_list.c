#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char usn[15], name[20], branch[10], sem[5], phone[10];
    struct node *link;

} node;


node *first = NULL, *temp, *sLast, *newNode;
int ch, i, count;

void stack()
{
    while (1)
    {
        printf("\nSTACK IMPLEMENTATION USING SINGLY LINKED LIST\n");
        printf("1. Insert front\n2. Delete front\n3. Display\n4. Exit from stack menu\n");
        printf("\nEnter your choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert_front();
            break;
        case 2:
            delete_front();
            break;

        case 3:
            display();
            break;

        case 4:
            return;

        default:
            printf("Invalid choice\n");
        }
    }
}

void queue()
{
    while (1)
    {
        printf("\nQUEUE IMPLEMENTATION USING SINGLY LINKED LIST\n");
        printf("1. Insert rear\n2. Delete rear\n3. Display\n4. Exit from queue menu\n");
        printf("\nEnter your choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert_rear();
            break;
        case 2:
            delete_rear();
            break;

        case 3:
            display();
            break;

        case 4:
            return;

        default:
            printf("Invalid choice\n");
        }
    }
}

void create()
{
    printf("\nEnter the number of students\n");
    scanf("%d", &count);

    for (i = 0; i < count; i++)
        insert_front();

    printf("\nList of %d students has been created.\n", count);
}

void display()
{
    if (first == NULL)
    {
        printf("\nList is empty!\n");
        return;
    }

    temp = first;
    count = 0;

    printf("\nUSN\tName\tBranch\tSem\tPhone\n");
    while (temp != NULL)
    {
        printf("%s\t%s\t%s\t%s\t%s\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phone);
        temp = temp->link;
        count++;
    }
    
    printf("\nTotal students = %d\n", count);
}

void insert_front()
{
    newNode = (node *)malloc(sizeof(node));
    printf("Enter the student's USN, Name, Branch, Sem and Phone no.\n");
    scanf("%s %s %s %s %s", newNode->usn, newNode->name, newNode->branch, newNode->sem, newNode->phone);
    newNode->link = first;
    first = newNode;
}

void delete_front()
{
    if (first == NULL)
    {
        printf("\nList is empty!\n");
        return;
    }

    temp = first;
    first = first->link;
    free(temp);
}

void insert_rear()
{
    newNode = (node *)malloc(sizeof(node));
    printf("Enter the student's USN, Name, Branch, Sem and Phone no.\n");
    scanf("%s %s %s %s %s", newNode->usn, newNode->name, newNode->branch, newNode->sem, newNode->phone);

    temp = first;

    if (first == NULL)
        temp = first = newNode;
    else
        while (temp->link != NULL)
            temp = temp->link;

    temp->link = newNode;
    newNode->link = NULL;
}

void delete_rear()
{
    if (first == NULL)
    {
        printf("\nList is empty!\n");
        return;
    }

    sLast = temp = first;

    while (temp->link != NULL)
    {
        sLast = temp;
        temp = temp->link;
    }

    sLast->link = NULL;
    free(temp);
}

int main()
{

    while (1)
    {
        printf("\nSTUDENT DATA RECORD USING SINGLY LINKED LIST\n");
        printf("1. Create a list of students\n2. Display list\n3. Insertion and Deletion from front (Stack)\n4. Insertion and Deletion from rear(Queue)\n5. Exit\n");
        printf("\nEnter your choice:");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            create();
            break;

        case 2:
            display();
            break;

        case 3:
            stack();
            break;

        case 4:
            queue();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice\n");
            break;
        }
    }
}