#include <stdio.h>
#include <stdlib.h>

int a[6][6] = {
 {0,1,0,0,1,0},   
 {1,0,1,0,1,0},   
 {0,1,0,1,0,0},   
 {0,0,1,0,1,1},   
 {1,1,0,1,0,0},   
 {0,0,0,1,0,0}  
}
,visited[6] = {0,0,0,0,0},m = 6,i,j;

void create(){
    printf("Enter the number of vertices: ");
    scanf("%d", &m);
    printf("Enter the adjacency matrix of the graph:\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < m; j++)
            scanf("%d",&a[i][j]);    
}

void bfs()
{

}

void dfs(int s)
{
    printf("%d ",s);
    visited[s] = 1;

    for (i = 0; i < 10; i++)
    {
        if (a[s][i] && !visited[i])
            dfs(i);
    }
    
}

void main(){

    dfs(0);

    /* int ch, s;

    while (1)
    {
        printf("\n1. Create graph\n2. BFS\n3. DFS\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            create();
            break;
            
        case 2:
            //Code
            break;
            
        case 3:
            printf("Enter the starting vertex: ");
            scanf("%d",&s);
            dfs(s);
            break;
        case 4: exit(0);

        default: printf("Invalid choice\n");
            break;
        }
    } */
    
}