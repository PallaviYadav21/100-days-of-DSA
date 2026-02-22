//Count Nodes in Linked List

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
int main() {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int n, i, value;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);
        newNode->data = value;
        newNode->next = NULL;
        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    int total = countNodes(head);
    printf("Total number of nodes = %d", total);
    return 0;
}

/*Output
Enter number of nodes: 4
Enter data for node 1: 10
Enter data for node 2: 20
Enter data for node 3: 30
Enter data for node 4: 40
Total number of nodes = 4
*/