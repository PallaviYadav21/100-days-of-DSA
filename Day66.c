//Problem: Detect cycle in directed graph using DFS and recursion stack.

#include <stdio.h>
#include <stdbool.h>
#define MAX 100
int graph[MAX][MAX];
bool visited[MAX];
bool recStack[MAX];
int n;
bool dfs(int v) {
    visited[v] = true;
    recStack[v] = true;
    for (int i = 0; i < n; i++) {
        if (graph[v][i]) {
            if (!visited[i] && dfs(i))
                return true;
            else if (recStack[i])
                return true;
        }
    }
    recStack[v] = false;
    return false;
}
bool hasCycle() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i))
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
        recStack[i] = false;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
    printf("Enter directed edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
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
Enter directed edges (u v):
0 1
1 2
2 3
3 1
YES
*/