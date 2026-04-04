//Problem Statement: Construct a binary tree from given preorder and inorder traversal arrays.

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}
int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}
struct Node* buildTree(int preorder[], int inorder[], int* preIndex, int inStart, int inEnd) {
    if (inStart > inEnd)
        return NULL;
    int rootVal = preorder[*preIndex];
    (*preIndex)++;
    struct Node* root = newNode(rootVal);
    int inIndex = findIndex(inorder, inStart, inEnd, rootVal);
    root->left = buildTree(preorder, inorder, preIndex, inStart, inIndex - 1);
    root->right = buildTree(preorder, inorder, preIndex, inIndex + 1, inEnd);
    return root;
}
void postorder(struct Node* root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
int main() {
    int N;
    scanf("%d", &N);
    int preorder[N], inorder[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &preorder[i]);
    for (int i = 0; i < N; i++)
        scanf("%d", &inorder[i]);
    int preIndex = 0;
    struct Node* root = buildTree(preorder, inorder, &preIndex, 0, N - 1);
    postorder(root);
    return 0;
}

/*Output
5
1 2 4 5 3
4 2 5 3 1
4 3 5 2 1 
*/