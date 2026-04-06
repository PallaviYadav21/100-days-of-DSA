//Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

#include <stdio.h>
#include <stdbool.h>
#define MAX 100
int adj[MAX][MAX];
bool visited[MAX];
int n;
bool dfs(int v, int parent) {
    visited[v] = true;
    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!visited[i]) {
                if (dfs(i, v))
                    return true;
            }
            else if (i != parent) {
                return true;
            }
        }
    }
    return false;
}
bool hasCycle() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return true;
        }
    }
    return false;
}
int main() {
    int m, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}

/*Output
Enter number of vertices: 4
Enter number of edges: 4
Enter edges (u v):
0 1
0 2
0 3
1 2
YES
*/