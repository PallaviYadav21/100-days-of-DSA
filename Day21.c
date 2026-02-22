//Create and Traverse Singly Linked List

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
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
        }
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    printf("Linked List Elements are: ");
    temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
    return 0;
}

/*Output
Enter number of nodes: 4
Enter data for node 1: 10
Enter data for node 2: 20
Enter data for node 3: 30
Enter data for node 4: 40
Linked List Elements are: 10 -> 20 -> 30 -> 40 -> NULL
*/