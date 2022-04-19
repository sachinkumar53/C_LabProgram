#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char ssn[15], name[20], dept[10], desig[10], sal[10], phone[10];
    struct node *plink, *nlink;
} node;


node *first = NULL, *temp, *newnode;

int i, n;

void create() {
    printf("\nEnter the number of employees\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the details of employee %d\n", (i + 1));
        insert_rear();
    }
}

void display() {
    if (first == NULL) {
        printf("\nList is empty!\n");
        return;
    }

    temp = first;
    int total = 0;
    printf("\nSSN\t Name\t Department\t Designation\t Sal\t Phone no.\n");
    while (temp != NULL) {
        printf("%s\t%s\t%s\t%s\t%s\t%s\n", temp->ssn, temp->name, temp->dept, temp->desig, temp->sal, temp->phone);
        temp = temp->nlink;
        total++;
    }
    printf("\nTotal employees = %d\n", total);
}

void insert_front() {
    newnode = (node *) malloc(sizeof(node));
    printf("\n Enter SSN, Name, Department, Designation, Sal, Phone no.\n");
    scanf("%s %s %s %s %s %s", newnode->ssn, newnode->name, newnode->dept, newnode->desig, newnode->sal,newnode->phone);
    newnode->plink = NULL;
    newnode->nlink = first;
    
    if (first != NULL)
        first->plink = newnode;

    first = newnode;
}

void delete_front() {
    if (first == NULL) {
        printf("\n List is empty!\n");
        return;
    }

    temp = first;
    first = first->nlink;
    first->plink = NULL;
    free(temp);
}

void insert_rear() {
    newnode = (node *) malloc(sizeof(node));
    printf("\nEnter SSN, Name, Department, Designation, Sal, Phone no.\n");
    scanf("%s %s %s %s %s %s", newnode->ssn, newnode->name, newnode->dept, newnode->desig, newnode->sal,newnode->phone);

    newnode->nlink = NULL;

    if (first == NULL) {
        newnode->plink = NULL;
        first = newnode;
    } else {
        temp = first;
        while (temp->nlink != NULL)
            temp = temp->nlink;

        temp->nlink = newnode;
        newnode->plink = temp;
    }
}

void delete_rear() {
    if (first == NULL) {
        printf("\nList is empty!\n");
        return;
    }

    temp = first;

    while (temp->nlink != NULL)
        temp = temp->nlink;

    if (temp->plink == NULL)
        first = NULL;
    else
        (temp->plink)->nlink = NULL;
        
    free(temp);
}

void double_ended_queue(){
    int ch;
    while (1)
    {
        printf("\nDOUBLE ENDED QUEUE MENU");
        printf("\n1. Insert from front\n2. Insert from rear\n3. Delete from front\n4. Delete from rear\n5. Display\n6. Back to main menu\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            insert_front();
            break;
        
        case 2:
            insert_rear();
            break;
        
        case 3:
            delete_front();
            break;
        
        case 4:
            delete_rear();
            break;
        
        case 5: display();
            break;

        case 6: return;

        default: printf("\nInvalid choice\n");
            break;
        }
    }
    
}

int main() {
    int ch;
    while (1) {
        printf("\nEMPLOYEE DATA USING DOUBLY LINKED LIST\n");
        printf("1. Create a list of employees\n2. Display list\n3. Insert item at front\n4. Delete item from front\n5. Insert item at rear\n6. Delete item from rear\n7. Double Ended Queue\n8. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert_front();
                break;
            case 4:
                delete_front();
                break;
            case 5:
                insert_rear();
                break;
            case 6:
                delete_rear();
                break;
            
            case 7:
                double_ended_queue();
                break;
            
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}
