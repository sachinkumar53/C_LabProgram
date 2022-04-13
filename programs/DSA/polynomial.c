#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node
{
    int cf, px, py, pz;
    struct node *link;
} Node;

Node *getNewNode()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Insufficient memory\n");
        exit(0);
    }
    return newNode;
}

Node *insert_rear(int cf, int px, int py, int pz, Node *head)
{
    Node *newNode = getNewNode();

    newNode->cf = cf;
    newNode->px = px;
    newNode->py = py;
    newNode->pz = pz;
    newNode->link = head;

    Node *temp = head->link;

    while (temp->link != head)
        temp = temp->link;

    temp->link = newNode;

    return head;
}

Node *read_poly()
{
    Node *head = getNewNode();
    head->link = head;
    
    printf("%d\n", head);
    printf("%d\n",head->link);

    int cf, px, py, pz, ch;
    do
    {
        ch = 0;
        printf("Enter coeff, px, py and pz\n");
        scanf("%d%d%d%d", &cf, &px, &py, &pz);
        head = insert_rear(cf, px, py, pz, head);
        printf("\nPress 1 to continue, otherwise 0: ");
        scanf("%d", &ch);
    } while (ch != 0);

    return head;
}

void display(Node *head)
{
    Node *temp;

    if (head->link == head)
    {
        printf("Polynomial does not exist\n");
        return;
    }else{
        printf("Polynomial exist: %d == %d\n",*head,head->link);
    }

    temp = head->link;

    printf("\n");
    while (temp != head)
    {
        printf("%dx^%dy^%dz^%d", temp->cf, temp->px, temp->py, temp->pz);

        if (temp->link != head)
            printf(" + ");

        temp = temp->link;
    }
    printf("\n");
}

void evaluate(Node *head)
{
    int x,y,z;
    printf("%d\n", head->cf);
    float result = 0.0;

    printf("Enter the value of x, y and z\n");
    scanf("%d%d%d",&x,&y,&z);
    
    Node *temp = head;
    
    do
    {
        int cf = temp->cf;
        float px = pow(x,(temp->px));
        float py = pow(y,(temp->py));
        float pz = pow(z,(temp->pz));
        result += cf*px*py*pz;
        temp = temp->link;
    } while (temp->link != head);

    printf("Result is: %f\n",result);
}

void main()
{
    int ch;
    
    Node *head;

    while (1)
    {
        printf("\n\n1.Evaluate polynomial\n2.Add two polynomials\n3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter a polynomial to evaluate:\n");
            head = read_poly();
            display(head);
            evaluate(head);
            break;

        case 2:
            break;

        case 3:
            exit(0);
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    }
}