//Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* insert(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
        return newNode;
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}
struct Node* deleteKey(struct Node* head, int key) {
    struct Node *temp = head, *prev = NULL;
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key not found!\n");
        return head;
    }
    prev->next = temp->next;
    free(temp);
    return head;
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
    int n, value, key;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        head = insert(head, value);
    }
    printf("Linked List: ");
    display(head);
    printf("Enter key to delete: ");
    scanf("%d", &key);
    head = deleteKey(head, key);
    printf("Updated List: ");
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
Linked List: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
Enter key to delete: 20
Updated List: 10 -> 30 -> 40 -> 50 -> NULL
*/