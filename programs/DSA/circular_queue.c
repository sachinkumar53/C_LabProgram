#include <stdio.h>
#define SIZE 5

int queue[SIZE], front = -1, rear = -1, count = 0;

void enqueue();
void dequeue();
void display();

int main(){
    int ch;
    while (1)
    {
        printf("\n-------Circular queue operation menu-------\n");
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
    if (count == SIZE)
    {
        printf("Queue is full.\n");
    }else{
        printf("Enter the item to insert.\n");
        scanf("%d",&item);
        if (front == -1)
            front++;

        rear = (rear+1)/SIZE;
        queue[rear] = item;
        count++;
        printf("%d is inserted in the queue\n",item);
    }
}

void dequeue(){

    int item;
    if (count == 0)
    {
        printf("Queue is Empty.\n");
    }else{
        item = queue[front];
        front++;
        rear = (rear+1)/SIZE;
        printf("%d is removed from the queue\n",item);
        count--;
    }
}

void display(){
    
    if (count == 0)
    {
        printf("Queue is Empty.\n");
    }else{
        int j = front;
        for (int i = 0; i <= count; i++){
            printf("%d ",queue[j]);
            j = (j+1)%SIZE;
        }

        printf("\n"); 
    }    
}