//Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node *front = NULL, *rear = NULL;
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if(front == NULL) {
        front = rear = newNode;
        newNode->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
}
void dequeue() {
    if(front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    if(front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front;
    }
    printf("Dequeued: %d\n", temp->data);
    free(temp);
}
void display() {
    if(front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != front);
    printf("\n");
}
int main() {
    int n, m, x;
    printf("Enter number of elements to enqueue: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }
    display();
    printf("Enter number of dequeue operations: ");
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        dequeue();
    }
    display();
    return 0;
}

/*Output
Enter number of elements to enqueue: 5
Enter 5 elements:
10 20 30 40 50
Queue elements: 10 20 30 40 50 
Enter number of dequeue operations: 2
Dequeued: 10
Dequeued: 20
Queue elements: 30 40 50
*/