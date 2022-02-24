#include <stdio.h>

int main()
{
    int n, i, j, a[10][10], sum;
    printf("Enter the order of the square matrix\n");
    scanf("%d", &n);

    printf("Enter the elements of the matrix\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    sum = 0;

    for (i = 0; i < n; i++)
    {
        sum += a[i][i];
    }

    printf("The sum of principle diagonal elements is %d\n", sum);

    return 0;
}
