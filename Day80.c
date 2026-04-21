//Problem: Given a weighted graph with n vertices, implement the Floyd-Warshall algorithm to compute the shortest distances between every pair of vertices. The graph may contain positive or negative edge weights, but it does not contain any negative weight cycles.

#include <stdio.h>
#define INF 1000000000
int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int graph[n][n];
    int dist[n][n];
    printf("Enter adjacency matrix (use -1 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == -1) {
                if (i == j)
                    dist[i][j] = 0;
                else
                    dist[i][j] = INF;
            } else {
                dist[i][j] = graph[i][j];
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
    printf("\nShortest distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("-1 ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
    return 0;
}

/*Output
Enter number of vertices: 4
Enter adjacency matrix (use -1 for no edge):
0 5 -1 10
-1 0 3 -1
1 -1 5 2
-1 -1 9 0

Shortest distance matrix:
0 5 8 10 
4 0 3 5 
1 6 5 2 
10 15 9 0 
*/