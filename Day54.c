//Problem Statement:Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* queue[MAX];
int front = -1, rear = -1;
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void enqueue(struct Node* node) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = node;
}
struct Node* dequeue() {
    if (front == -1 || front > rear) return NULL;
    return queue[front++];
}
int isEmpty() {
    return front == -1 || front > rear;
}
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = createNode(arr[0]);
    enqueue(root);
    int i = 1;
    while (!isEmpty() && i < n) {
        struct Node* curr = dequeue();
        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(curr->left);
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }
    return root;
}
void zigzagTraversal(struct Node* root) {
    if (!root) return;
    front = rear = -1;
    enqueue(root);
    int leftToRight = 1;
    while (!isEmpty()) {
        int size = rear - front + 1;
        int level[MAX];
        for (int i = 0; i < size; i++) {
            struct Node* curr = dequeue();
            level[i] = curr->data;
            if (curr->left) enqueue(curr->left);
            if (curr->right) enqueue(curr->right);
        }
        if (leftToRight) {
            for (int i = 0; i < size; i++)
                printf("%d ", level[i]);
        } else {
            for (int i = size - 1; i >= 0; i--)
                printf("%d ", level[i]);
        }
        leftToRight = !leftToRight;
    }
}
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int arr[MAX];
    printf("Enter level order values (-1 for NULL): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* root = buildTree(arr, n);
    printf("Zigzag Traversal:\n");
    zigzagTraversal(root);
    return 0;
}

/*Output
Enter number of nodes: 7
Enter level order values (-1 for NULL): 1 2 3 4 7 5 8
Zigzag Traversal:
1 3 2 4 7 5 8 
*/