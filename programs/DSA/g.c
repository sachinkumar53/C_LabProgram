#include <stdio.h>
#include <stdlib.h>
int a[20][20], q[20], visited[20], n, f = 0, r = -1, count = 1, flag = 0;
void create()
{
    int i, j;
    printf("\nEnter the number of vertices of the directed graph: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix of the graph:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
}
void bfs(int v)
{
    int i;
    for (i = 1; i <= n; i++)
        if (a[v][i] == 1 && visited[i] == 0)
            q[++r] = i;
    if (f <= r)
    {
        visited[q[f]] = 1;
        bfs(q[f++]);
    }
}
void dfs(int i)
{
    visited[i] = 1;

    for (int j = 1; j <= n; j++)
    {
        if (a[i][j] == 1 && visited[j] == 0)
        {
            printf("%d\t", j);
            count++;
            dfs(j);
        }
    }
}
void main()
{
    int v, i, j, choice;
    while (1)
    {
        printf("\n 1. create\n 2.BFS\n 3.DFS\n 4.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            printf("\n Enter the starting vertex:\n");
            scanf("%d", &v);
            for (i = 1; i <= n; i++)
            {
                q[i] = 0;
                visited[i] = 0;
            }
            bfs(v);
            printf("\n The nodes which are reachable from %d are:\n", v);
            for (i = 1; i <= n; i++)
                if (visited[i])
                    printf("%d\t", i);
            break;
        case 3:
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
            if (flag == 1)
                printf("\n Graph is not strongly connected");
            else
                printf("\n Graph is strongly connected");
            break;
        case 4:
            exit(0);
        }
    }
}