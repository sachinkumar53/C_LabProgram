#include <stdio.h>
#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

void enqueue();
void dequeue();
void display();

int main(){
    int ch;
    while (1)
    {
        printf("\n-------Ordinary queue operation menu-------\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        
        printf("\nEnter your choice\n");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1: enqueue();
            break;

        case 2: dequeue();
            break;

        case 3: display();
            break;
        
        case 4: return 0;
            break;
        
        default: printf("Invalid choice");
        }
    }
}

void enqueue(){

    int item;
    if (rear == (SIZE-1))
    {
        printf("Queue is full.\n");
    }else{
        printf("Enter the item to insert.\n");
        scanf("%d",&item);
        if (front == -1)
            front++;

        rear++;
        queue[rear] = item;
        printf("%d is inserted in the queue\n",item);
    }
}

void dequeue(){

    int item;
    if (front == -1)
    {
        printf("Queue is Empty.\n");
    }else{
        item = queue[front];
        front++;
        if (front > rear)
            front = rear = -1;
        printf("%d is removed from the queue\n",item);
    }
}

void display(){
    
    if (rear == -1)
    {
        printf("Queue is Empty.\n");
    }else{
        for (int i = front; i <= rear; i++)
            printf("%d ",queue[i]);

        printf("\n"); 
    }    
}