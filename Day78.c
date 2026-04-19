//Problem Statement Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

#include <stdio.h>
#include <limits.h>
#define MAX 100
int graph[MAX][MAX];
int visited[MAX];
int n, m;
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            graph[i][j] = INT_MAX;
        }
    }
    int u, v, w;
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }
    visited[1] = 1;
    int edges = 0;
    int total_weight = 0;
    while(edges < n - 1) {
        int min = INT_MAX;
        int x = -1, y = -1;
        for(int i = 1; i <= n; i++) {
            if(visited[i]) {
                for(int j = 1; j <= n; j++) {
                    if(!visited[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        if(x != -1 && y != -1) {
            visited[y] = 1;
            total_weight += min;
            edges++;
        }
    }
    printf("%d\n", total_weight);
    return 0;
}