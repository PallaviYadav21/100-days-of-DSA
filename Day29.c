//Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

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
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL)
        return newNode;
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;
    struct Node* temp = head;
    int count = 1;
    while (temp->next != NULL) {
        temp = temp->next;
        count++;
    }
    temp->next = head;
    k = k % count;
    int stepsToNewHead = count - k;
    temp = head;
    for (int i = 1; i < stepsToNewHead; i++)
        temp = temp->next;
    struct Node* newHead = temp->next;
    temp->next = NULL;
    return newHead;
}
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;
    int n, value, k;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        head = insertEnd(head, value);
    }
    printf("Enter value of k: ");
    scanf("%d", &k);

    printf("Original List:\n");
    display(head);
    head = rotateRight(head, k);
    printf("Rotated List:\n");
    display(head);
    return 0;
}

/*Output
Enter number of nodes: 5
Enter value: 10
Enter value: 20
Enter value: 30
Enter value: 40
Enter value: 50
Enter value of k: 2
Original List:
10 -> 20 -> 30 -> 40 -> 50 -> NULL
Rotated List:
40 -> 50 -> 10 -> 20 -> 30 -> NULL
*/