#include <stdio.h>
#include <stdlib.h>

int a[20][20], visited[20], q[20], n, count = 1, flag = 0, f = 0, r = -1;

void create()
{
    int i, j;
    printf("Enter the no. of directed vertex\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
}

void bfs(int v)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        if (a[v][i] == 1 && visited[i] == 0)
            q[++r] = i;
    }

    if (f <= r)
    {
        visited[q[f]] = 1;
        bfs(q[f++]);
    }
}

void dfs(int v)
{
    visited[v] = 1;
    int i;

    for (i = 1; i <= n; i++)
    {
        if (a[v][i] == 1 && visited[i] == 0)
        {
            printf("%d ", i);
            count++;
            dfs(i);
        }
    }
}

void main()
{

    int ch, v, i, j;
    while (1)
    {
        printf("\n1.Create\n2.BFS\n3.DFS\n4.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;

        case 2:
            printf("\nEnter the starting vertex: ");
            scanf("%d", &v);
            for (i = 1; i <= n; i++)
            {
                q[i] = 0;
                visited[i] = 0;
            }
            bfs(v);
            printf("Nodes reachable from given vertex is\n");
            for (i = 1; i <= n; i++)
                if (visited[i] == 1)
                    printf("%d ", i);

            break;

        case 3:
            printf("\nEnter the starting vertex: ");
            scanf("%d", &v);
            for (i = 1; i <= n; i++)
            {
                for (j = 1; j <= n; j++)
                    visited[j] = 0;

                dfs(i);
                printf("\n");
                if (count < n)
                {
                    flag = 1;
                    break;
                }
                else
                    count = 1;
            }

            if (flag)
            {
                printf("Graph is strongly connected\n");
            }
            else
            {
                printf("Graph is not strongly connected\n");
            }
            break;

        case 4:
            exit(0);

        default: printf("Invalid choice\n");
            break;
        }
    }
}