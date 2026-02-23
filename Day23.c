//Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
struct Node* insert(struct Node* head, int data) {
    struct Node* temp = newNode(data);
    if (head == NULL) return temp;
    struct Node* p = head;
    while (p->next != NULL)
        p = p->next;
    p->next = temp;
    return head;
}
struct Node* merge(struct Node* a, struct Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    if (a->data <= b->data) {
        a->next = merge(a->next, b);
        return a;
    } else {
        b->next = merge(a, b->next);
        return b;
    }
}
void print(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node *list1 = NULL, *list2 = NULL;
    int n1, n2, value;
    printf("Enter number of elements in List 1: ");
    scanf("%d", &n1);
    printf("Enter sorted elements:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &value);
        list1 = insert(list1, value);
    }
    printf("Enter number of elements in List 2: ");
    scanf("%d", &n2);
    printf("Enter sorted elements:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &value);
        list2 = insert(list2, value);
    }
    struct Node* result = merge(list1, list2);
    printf("Merged List:\n");
    print(result);
    return 0;
}

/*Output
Enter number of elements in List 1: 5
Enter sorted elements:
10 20 30 40 50
Enter number of elements in List 2: 4
Enter sorted elements:
15 25 35 45
Merged List:
10 -> 15 -> 20 -> 25 -> 30 -> 35 -> 40 -> 45 -> 50 -> NULL
*/