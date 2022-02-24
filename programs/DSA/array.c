#include <stdio.h>
#define smax 50

void create();
void display();
void insert();
void delete ();

int arr[smax],n,count,i;

int main()
{
    int ch;

    while (1)
    {
        printf("\nARRAY OPERATION MENU\n");
        printf("1. Create an array\n2. Display elements of the array\n3. Insert at a position\n4. Delete from a position\n5. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            create();
            break;

        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            delete ();
            break;
        case 5:
            return 0;

        default:
            printf("Invalid choice\n");
            break;
        }
    }
}

void create()
{
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    
    if (n <= 0 || n > smax)
    {
        printf("Invalid size of the array\n");
        return 0;
    }
    
    printf("Enter the elements of the array\n");
    for (i = 0; i < n; i++)
        scanf("%d",&arr[i]);
    
    count = n;
    printf("Array of %d elements is created\n",n);
}

void display(){
    if (n == 0 || count == 0)
    {
        printf("Array is empty!\n");
        return;
    }

    printf("Elements of the array are:\n");
    for (i = 0; i < count; i++)
        printf("%d ",arr[i]);

    printf("\n");
}

void insert(){
    if (count == n)
    {
        printf("Can not insert item. Array is full!\n");
        return;
    }

    int item,pos;
    printf("Enter the element and its position\n");
    scanf("%d%d",&item,&pos);
    if (pos <= 0)
    {
        printf("Invalid position\n");
        return;
    }
    pos--;
    for (i = (n-1); i >= pos; i--)
        arr[i+1] = arr[i];
    
    arr[pos] = item;
    count++;
    printf("%d is inserted at position %d\n",item,pos);
}

void delete(){
    if (count == 0 || n == 0)
    {
        printf("Can not delete item. Array is empty!\n");
        return;
    }

    int item,pos;
    printf("Enter position of the element to be deleted\n");
    scanf("%d",&pos);
    if (pos <= 0)
    {
        printf("Invalid position\n");
        return;
    }
    pos--;

    item = arr[pos];
    for (i = pos; i < n; i++)
        arr[i] = arr[i+1];
    
    count--;
    printf("%d is deleted from position %d\n",item,pos);
}
