//Problem: Perform DFS starting from a given source vertex using recursion.

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Node {
    int vertex;
    struct Node* next;
};
struct Node* adjList[MAX];
int visited[MAX];
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;
}
void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);
    struct Node* temp = adjList[v];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            DFS(adjVertex);
        }
        temp = temp->next;
    }
}
int main() {
    int n, m, u, v, s;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }
    printf("Enter number of edges: ");
    scanf("%d", &m);
    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    printf("Enter starting vertex: ");
    scanf("%d", &s);
    printf("DFS Traversal: ");
    DFS(s);
    return 0;
}

/*Output
Enter number of vertices: 5
Enter number of edges: 4
Enter edges (u v):
0 1
0 2
1 3
1 4
Enter starting vertex: 1
DFS Traversal: 1 4 3 0 2 
*/