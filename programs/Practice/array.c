#include <stdio.h>
#define MAX 100

int a[MAX],n;

void create(){
    if (n == 0)
    {
        printf("Enter the number of elements\n");
        scanf("%d",&n);
        printf("Enter the elements\n");
        for (int i = 0; i < n; i++)
            scanf("%d",&a[i]);
        
        printf("Array is created.\n");
    }else   printf("Array is already created.\n");
    
}


void insert_pos(){
    int pos,e;
    printf("Enter the pos and element to insert: ");
    scanf("%d%d",&pos,&e);
    if (pos <= 0 || pos > n)
    {
        printf("Invalid position\n");
        return;
    }
    --pos;
    for (int i = n-1; i >= pos; i--)
        a[i+1] = a[i];
    a[pos] = e;
    n++;
    printf("Item inserted to array\n");
}

void delete_pos(){
    int pos,e;
    printf("Enter the pos of element to delete: ");
    scanf("%d",&pos);
    if (pos <= 0 || pos > n)
    {
        printf("Invalid position\n");
        return;
    }
    e = a[--pos];
    for (int i = pos; i < n; i++)
        a[i] = a[i+1];
    n--;
    printf("%d deleted from array\n",e);
}

void display(){
    if (n == 0)
    {
        printf("Array is not created\n");
    }else{
        for (int i = 0; i < n; i++)
            printf("%d\t",a[i]);
        printf("\n");
    }
    
}
int main()
{
    int ch;

    while (1)
    {
        printf("\nArray Menu\n");
        printf("1. Create\n2. Display\n3. Insert pos\n4. Delete pos\n5.Exit\n");
        printf("Enter your choice: ");
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
            insert_pos();
            break;
            
        case 4:
            delete_pos();
            break;
        
        case 5:
            return 0;
        
        default: printf("Invalid position\n");
            break;
        }
    }
        
    return 0;
}
