//Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int vertex;
    struct Node* next;
};
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}
void printGraph(struct Node* adj[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: ", i);
        struct Node* temp = adj[i];
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main() {
    int n, m;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    struct Node* adj[n];
    for (int i = 0; i < n; i++)
        adj[i] = NULL;
    printf("Enter edges (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }
    printf("Adjacency List:\n");
    printGraph(adj, n);
    return 0;
}

/*Output
Enter number of vertices: 4
Enter number of edges: 3
Enter edges (u v):
0 1
0 2
1 3
Adjacency List:
Vertex 0: 2 -> 1 -> NULL
Vertex 1: 3 -> 0 -> NULL
Vertex 2: 0 -> NULL
Vertex 3: 1 -> NULL
*/