//Problem Statement:Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Queue {
    struct Node* arr[1000];
    int front, rear;
};
void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}
void enqueue(struct Queue* q, struct Node* node) {
    if (q->rear == 999) return;
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = node;
}
struct Node* dequeue(struct Queue* q) {
    if (q->front == -1 || q->front > q->rear) return NULL;
    return q->arr[q->front++];
}
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Queue q;
    initQueue(&q);
    struct Node* root = createNode(arr[0]);
    enqueue(&q, root);
    int i = 1;
    while (i < n) {
        struct Node* curr = dequeue(&q);
        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(&q, curr->left);
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(&q, curr->right);
        }
        i++;
    }
    return root;
}
struct Node* findLCA(struct Node* root, int p, int q) {
    if (root == NULL) return NULL;
    if (root->data == p || root->data == q)
        return root;
    struct Node* left = findLCA(root->left, p, q);
    struct Node* right = findLCA(root->right, p, q);
    if (left && right)
        return root;
    return (left != NULL) ? left : right;
}
int main() {
    int n, i, p, q;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter level order values:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* root = buildTree(arr, n);
    printf("Enter two nodes: ");
    scanf("%d %d", &p, &q);
    struct Node* lca = findLCA(root, p, q);
    if (lca)
        printf("LCA is: %d\n", lca->data);
    else
        printf("LCA not found\n");
    return 0;
}

/*Output
Enter number of nodes: 7
Enter level order values:
3 5 1 6 8 4 9
Enter two nodes: 3 5
LCA is: 3*/