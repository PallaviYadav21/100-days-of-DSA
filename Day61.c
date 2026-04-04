//Problem: Build a graph with n vertices and m edges using adjacency matrix representation.The graph may be directed or undirected.

#include <stdio.h>
int main() {
    int n, m, i, u, v, type;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    int adj[n][n];
    for(i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
    printf("Enter 0 for Undirected graph, 1 for Directed graph: ");
    scanf("%d", &type);
    printf("Enter edges (u v):\n");
    for(i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        if(type == 0) {
            adj[v][u] = 1;
        }
    }
    printf("Adjacency Matrix:\n");
    for(i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    return 0;
}

/*Output
Enter number of vertices: 3
Enter number of edges: 2
Enter 0 for Undirected graph, 1 for Directed graph: 0 1
Enter edges (u v):
0 2
1 2
Adjacency Matrix:
0 1 0 
1 0 1 
0 1 0 
*/