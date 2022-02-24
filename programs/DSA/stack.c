#include <stdio.h>
#define SIZE 5

int stack[SIZE], i,top = -1;

void push();
void pop();
void display();

int main(){

    int ch;
    while (1)
    {
        printf("\n-----------Stack Operation Menu-----------\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        
        printf("\nEnter your choice\n");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1: push();
            break;

        case 2: pop();
            break;

        case 3: display();
            break;
        
        case 4: return 0;
            break;
        
        default: printf("Invalid choice");
        }
    }
    
}

void push(){
    int item;
    if (top == (SIZE-1))
    {
        printf("Stack is full. No more item can be inserted.\n");    
    }else{
        printf("Enter the item to insert\n");
        scanf("%d",&item);
        top++;
        stack[top] = item;
        printf("%d is inserted to the stack.\n",item);
    }
}

void pop(){
    int item;
    if (top == -1)
    {
        printf("Stack is Empty.\n");    
    }else{
        item = stack[top];
        top--;
        printf("%d is deleted from the stack.\n",item);
    }
}

void display(){
    
    if (top == -1)
    {
        printf("Stack is Empty.\n");    
    }else{
        printf("\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n",stack[i]);
        }
        
    }
}

