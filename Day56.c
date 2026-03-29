//Problem Statement: Check whether a given binary tree is symmetric around its center.

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
struct Node* queue[1000];
int front = 0, rear = 0;
void enqueue(struct Node* node) {
    queue[rear++] = node;
}
struct Node* dequeue() {
    return queue[front++];
}
struct Node* buildTree(int n) {
    if (n == 0) return NULL;
    int val;
    scanf("%d", &val);
    if (val == -1) return NULL;
    struct Node* root = newNode(val);
    enqueue(root);
    int count = 1;
    while (count < n) {
        struct Node* current = dequeue();
        scanf("%d", &val);
        count++;
        if (val != -1) {
            current->left = newNode(val);
            enqueue(current->left);
        }
        if (count >= n) break;
        scanf("%d", &val);
        count++;
        if (val != -1) {
            current->right = newNode(val);
            enqueue(current->right);
        }
    }
    return root;
}
int isMirror(struct Node* left, struct Node* right) {
    if (left == NULL && right == NULL)
        return 1;
    if (left == NULL || right == NULL)
        return 0;
    return (left->data == right->data) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}
int isSymmetric(struct Node* root) {
    if (root == NULL)
        return 1;
    return isMirror(root->left, root->right);
}
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter level order traversal:\n");
    struct Node* root = buildTree(n);
    if (isSymmetric(root))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}

/*Output
Enter number of nodes: 7
Enter level order traversal:
1 2 2 3 4 1 5
NO
*/