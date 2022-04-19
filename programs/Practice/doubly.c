#include <stdio.h>
#include <stdlib.h>

struct emp
{
    char ssn[20],name[20], dept[20], desig[20],sal[20],phone[10];
    struct emp *llink,*rlink;
};


typedef struct emp NODE;
NODE* first;

void create()
{
    int i,n;
    printf("Enter the number of employees\n");
    scanf("%d",&n);
    for (i = 0; i < n; i++)
        insert_rear();

    printf("Created list of %d employees\n",n);
}

void insert_front()
{
    NODE* node = (NODE*) malloc(sizeof(NODE));
    printf("Enter employee sssn, name, dept, desig, sal, phone\n");
    scanf("%s %s %s %s %s %s",node->ssn,node->name,node->dept,node->desig,node->sal,node->phone);
    node->llink = NULL;
    node->rlink = first;
    first->llink = node;
    first = node;
}

void insert_rear(){
    NODE* node = (NODE*) malloc(sizeof(NODE));
    printf("Enter employee sssn, name, dept, desig, sal, phone\n");
    scanf("%s %s %s %s %s %s",node->ssn,node->name,node->dept,node->desig,node->sal,node->phone);
    
    NODE* temp = first;
    
    while (temp->rlink != NULL)
        temp = temp->rlink;
    
    temp->rlink = node;
    node->llink = temp;
    node->rlink = NULL;
    
    if (first == NULL)
        first = node;
}

void delete_front()
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    
    NODE* temp = first;
    first = first->rlink;
    free(temp);
}

void delete_rear()
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    
    NODE* temp = first;
    while (temp->rlink != NULL)
        temp = temp->rlink;

    temp->llink->rlink = NULL;
    free(temp);
}

void display()
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    
    NODE* temp = first;
    printf("\nEnter employee sssn, name, dept, desig, sal, phone\n");
    int total = 0;
    while (temp != NULL){
        printf("%s %s %s %s %s %s",temp->ssn,temp->name,temp->dept,temp->desig,temp->sal,temp->phone);
        total++;
        temp = temp->rlink;
    }

}
