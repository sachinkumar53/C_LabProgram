#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *left, *right;
};

typedef struct tree NODE;

NODE *create(NODE *node, int data)
{
    if (node == NULL)
    {
        NODE *temp = (NODE *)malloc(sizeof(NODE));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }

    else if (data < node->data)
    {
        node->left = create(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = create(node->right, data);
    }

    return node;
}

NODE *search(NODE *node, int data)
{
    if (node == NULL)
    {
        printf("Element not found\n");
    }
    else if (data < node->data)
    {
        node->left = search(node->left,data);
    }
    else if (data > node->data)
    {
        node->right = search(node->right,data);
    }
    else
    {
        printf("Element %d is found\n", node->data);
    }

    return node;
}

void inorder(NODE *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

void preorder(NODE *node)
{
    if (node != NULL)
    {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(NODE *node)
{
    if (node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}

void main()
{
    int ch, i, data, n;
    NODE *root;
    while (1)
    {
        printf("\n1. Create\n2. Search\n3. Inorder\n4. Preorder\n5. Postorder\n6.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the number of elements\n");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                scanf("%d", &data);
                root = create(root,data);
            }
            break;
        case 2:
            printf("Enter the element to search\n");
            scanf("%d", &data);
            root = search(root, data);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            preorder(root);
            break;
        case 5:
            postorder(root);
            break;
        case 6:
            exit(0);
        default: printf("Invalid choice\n");
            break;
        }
    }
}