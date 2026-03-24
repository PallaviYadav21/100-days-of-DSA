//Problem Statement:Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}
struct Node* findLCA(struct Node* root, int p, int q) {
    while (root != NULL) {
        if (p < root->data && q < root->data)
            root = root->left;
        else if (p > root->data && q > root->data)
            root = root->right;
        else
            return root;
    }
    return NULL;
}
int main() {
    int n, i, val, p, q;
    struct Node* root = NULL;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter %d values:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("Enter two nodes to find LCA: ");
    scanf("%d %d", &p, &q);
    struct Node* lca = findLCA(root, p, q);
    if (lca != NULL)
        printf("LCA is: %d\n", lca->data);
    else
        printf("LCA not found\n");
    return 0;
}

/*Output
Enter number of nodes: 7
Enter 7 values:
6 2 4 8 9 1 5
Enter two nodes to find LCA: 2 5
LCA is: 2
*/