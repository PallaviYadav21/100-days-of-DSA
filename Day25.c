//Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

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
int countOccurrences(struct Node* head, int key) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key)
            count++;
        temp = temp->next;
    }
    return count;
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
    printf("Enter element to count: ");
    scanf("%d", &key);
    int result = countOccurrences(head, key);
    printf("Element %d occurs %d time(s).\n", key, result);
    return 0;
}

/*Output
Enter number of nodes: 5
Enter value: 10
Enter value: 20
Enter value: 30
Enter value: 40
Enter value: 50
Enter element to count: 20
Element 20 occurs 1 time(s).
*/