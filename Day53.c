//Problem Statement:Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    while (i < n) {
        struct Node* curr = queue[front++];
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}
struct Pair {
    struct Node* node;
    int hd;
};
void verticalOrder(struct Node* root) {
    if (!root) return;
    struct Pair queue[200];
    int front = 0, rear = 0;
    int map[200][200] = {0};
    int count[200] = {0};
    int offset = 100;
    queue[rear++] = (struct Pair){root, offset};
    while (front < rear) {
        struct Pair temp = queue[front++];
        struct Node* curr = temp.node;
        int hd = temp.hd;
        map[hd][count[hd]++] = curr->data;
        if (curr->left)
            queue[rear++] = (struct Pair){curr->left, hd - 1};
        if (curr->right)
            queue[rear++] = (struct Pair){curr->right, hd + 1};
    }
    printf("\nVertical Order Traversal:\n");
    for (int i = 0; i < 200; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
    }
}
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter level order values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* root = buildTree(arr, n);
    verticalOrder(root);
    return 0;
}

/*Output
Enter number of nodes: 7
Enter level order values:
1 2 3 4 5 6 7

Vertical Order Traversal:
4 
2 
1 5 6 
3 
7
*/