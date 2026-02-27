// Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
int findIntersection(struct Node* head1, struct Node* head2) {
    while (head1 != NULL) {
        struct Node* temp = head2;
        while (temp != NULL) {
            if (head1->data == temp->data) {
                return head1->data;
            }
            temp = temp->next;
        }
        head1 = head1->next;
    }
    return -1;
}
int main() {
    struct Node *head1 = NULL, *head2 = NULL;
    int n, m, value;
    printf("Enter number of nodes in first list: ");
    scanf("%d", &n);
    printf("Enter elements of first list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        append(&head1, value);
    }
    printf("Enter number of nodes in second list: ");
    scanf("%d", &m);
    printf("Enter elements of second list:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        append(&head2, value);
    }
    int result = findIntersection(head1, head2);
    if (result == -1)
        printf("No Intersection\n");
    else
        printf("Intersection point value: %d\n", result);
    return 0;
}

/*Output
Enter number of nodes in first list: 5
Enter elements of first list:
10 20 30 40 50
Enter number of nodes in second list: 4
Enter elements of second list:
15 25 35 40
Intersection point value: 40
*/