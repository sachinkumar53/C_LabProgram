#include <stdio.h>
#define MAX 5

int stk[MAX],top = -1;

void push(){
    int a;
    if (top == MAX-1)
    {
        printf("StackOverflow\n");
    }else{
        printf("Enter item to push\n");
        scanf("%d",&a);
        stk[++top] = a;
        printf("%d pushed to stack\n",a);        
    }
    
}

void pop(){
    if (top == -1)
    {
        printf("StackUnderflow\n");
    }else{
        int a = stk[top--];
        printf("%d poped from stack\n",a);        
    }
}

void display(){
    if (top == -1)
    {
        printf("Stack is empty\n");
    }else{
        for (int i = 0; i <= top; i++)
            printf("%d\t",stk[i]);
        printf("\n");
    }
    
}

void palindrome(){
    int rev[MAX];
    
    for(int i = top; i >= 0; i--)
        rev[top-i] = stk[i];

    int flag = 1;
    for (int i = 0; i <= top; i++)
    {
        if (rev[i] != stk[i])
        {
            flag = 0;
            break;
        }
        
    }
    
    if (flag)
    {
        printf("Pallindrome\n");
    }else printf("Not pallindrome\n");
    
}

int main()
{
    int ch;

    while (1)
    {
        printf("\nStack Menu\n");
        printf("1. PUSH\n2. Pop\n3. Palindrome\n4. Display\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            push();
            break;
            
        case 2:
            pop();
            break;
        
        case 3:
            palindrome();
            break;

        case 4:
            display();
            break;
            
        case 5:
            return 0;
        
        default: printf("Invalid position\n");
            break;
        }
    }
        
    return 0;
}
