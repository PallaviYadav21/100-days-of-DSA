//Construct a Binary Tree from the given level-order traversal.

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Queue {
    struct Node* arr[100];
    int front, rear;
};
void enqueue(struct Queue* q, struct Node* node) {
    q->arr[++q->rear] = node;
}
struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}
int isEmpty(struct Queue* q) {
    return q->front > q->rear;
}
struct Node* buildTree(int arr[], int n) {
    if (arr[0] == -1) return NULL;
    struct Node* root = createNode(arr[0]);  
    struct Queue q;
    q.front = 0;
    q.rear = -1;
    enqueue(&q, root);
    int i = 1;
    while (i < n && !isEmpty(&q)) {
        struct Node* current = dequeue(&q);
        if (arr[i] != -1) {
            current->left = createNode(arr[i]);
            enqueue(&q, current->left);
        }
        i++;
        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            enqueue(&q, current->right);
        }
        i++;
    }
    return root;
}
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* root = buildTree(arr, n);
    inorder(root);
    return 0;
}

/*Output
7
1 2 3 -1 5 -5 8 
2 5 1 -5 3 8 
*/