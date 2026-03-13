//Implement a Queue using a linked list supporting enqueue and dequeue operations.

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node *front = NULL, *rear = NULL;
void enqueue(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}
void dequeue() {
    if (front == NULL) {
        printf("-1\n");
        return;
    }
    struct Node* temp = front;
    printf("%d\n", temp->data);
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
}
int main() {
    int n, choice, value;
    printf("Enter number of operations: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("\n1. Enqueue\n2. Dequeue\nEnter operation: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(value);
        }
        else if (choice == 2) {
            dequeue();
        }
    }
    return 0;
}

/*Output
Enter number of operations: 5

1. Enqueue
2. Dequeue
Enter operation: 1
Enter value: 10

1. Enqueue
2. Dequeue
Enter operation: 1
Enter value: 20

1. Enqueue
2. Dequeue
Enter operation: 2
10

1. Enqueue
2. Dequeue
Enter operation: 1
Enter value: 30

1. Enqueue
2. Dequeue
Enter operation: 2
20
*/