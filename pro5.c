#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void topologicalSort(int V, int adj[MAX][MAX])
{
    int indeg[MAX] = {0}, q[MAX], front = 0, rear = -1;
    
    // Calculate indegree
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            if(adj[i][j]) indeg[j]++;
    
    // Add nodes with indegree 0 to queue
    for(int i = 0; i < V; i++)
        if(indeg[i] == 0) q[++rear] = i;
    
    printf("Topological ordering of vertices: ");
    while(front <= rear)
    {
        int u = q[front++];
        printf("%d ", u);
        
        // Reduce indegree of adjacent nodes
        for(int v = 0; v < V; v++)
            if(adj[u][v] && --indeg[v] == 0)
                q[++rear] = v;
    }
    printf("\n");
}

int main()
{
    int V, E, adj[MAX][MAX] = {0};
    
    printf("Enter vertices: ");
    scanf("%d", &V);
    
    printf("Enter edges: ");
    scanf("%d", &E);
    
    printf("Enter edges (u v):\n");
    for(int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }
    
    topologicalSort(V, adj);
    return 0;
}
