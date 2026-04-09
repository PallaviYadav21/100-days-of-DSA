//Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = -1;
void enqueue(int x) {
    queue[++rear] = x;
}
int dequeue() {
    return queue[front++];
}
int isEmpty() {
    return front > rear;
}
void topologicalSort(int n) {
    int i, j;
    int count = 0;
    int result[MAX];
    for (i = 0; i < n; i++) {
        indegree[i] = 0;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }
    while (!isEmpty()) {
        int node = dequeue();
        result[count++] = node;
        for (j = 0; j < n; j++) {
            if (adj[node][j] == 1) {
                indegree[j]--;
                if (indegree[j] == 0) {
                    enqueue(j);
                }
            }
        }
    }
    if (count != n) {
        printf("Cycle exists! Topological sort not possible.\n");
    } else {
        printf("Topological Order: ");
        for (i = 0; i < count; i++) {
            printf("%d ", result[i]);
        }
    }
}
int main() {
    int n, m, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    printf("Enter number of edges: ");
    scanf("%d", &m);
    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }
    topologicalSort(n);
    return 0;
}

/*Output
Enter number of vertices: 5
Enter number of edges: 2
Enter edges (u v):
5 2
3 4
Topological Order: 0 1 2 3 4 
*/