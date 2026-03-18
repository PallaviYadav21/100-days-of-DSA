//Problem: Level Order Traversal

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int data) {
    if (data == -1) return NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* queue[100];
int front = -1, rear = -1;
void enqueue(struct Node* node) {
    if (front == -1) front = 0;
    queue[++rear] = node;
}
struct Node* dequeue() {
    return queue[front++];
}
struct Node* buildTree(int n) {
    int val, i;
    printf("Enter root value: ");
    scanf("%d", &val);
    struct Node* root = createNode(val);
    if (root == NULL) return NULL;
    enqueue(root);
    for (i = 1; i < n; i++) {
        struct Node* parent = queue[front];
        printf("Enter left child of %d: ", parent->data);
        scanf("%d", &val);
        parent->left = createNode(val);
        if (parent->left != NULL)
            enqueue(parent->left);
        i++;
        if (i >= n) break;
        printf("Enter right child of %d: ", parent->data);
        scanf("%d", &val);
        parent->right = createNode(val);
        if (parent->right != NULL)
            enqueue(parent->right);
        dequeue();
    }
    return root;
}
void levelOrder(struct Node* root) {
    if (root == NULL) return;
    front = rear = -1;
    enqueue(root);
    printf("Level Order Traversal: ");
    while (front <= rear) {
        struct Node* temp = dequeue();
        printf("%d ", temp->data);
        if (temp->left) enqueue(temp->left);
        if (temp->right) enqueue(temp->right);
    }
}
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    struct Node* root = buildTree(n);
    levelOrder(root);
    return 0;
}

/*Output
Enter number of nodes: 5
Enter root value: 1
Enter left child of 1: 2
Enter right child of 1: 3
Enter left child of 2: 4
Enter right child of 2: 5
Level Order Traversal: 1 2 3 4 5 
*/