//A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

#include <stdio.h>
#define MAX 100
int deque[MAX];
int front = -1;
int rear = -1;
int isFull() {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1))
        return 1;
    return 0;
}
int isEmpty() {
    if (front == -1)
        return 1;
    return 0;
}
void push_front(int value) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    }
    else if (front == 0) {
        front = MAX - 1;
    }
    else {
        front--;
    }
    deque[front] = value;
}
void push_back(int value) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    }
    else if (rear == MAX - 1) {
        rear = 0;
    }
    else {
        rear++;
    }
    deque[rear] = value;
}
void pop_front() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted element: %d\n", deque[front]);
    if (front == rear) {
        front = rear = -1;
    }
    else if (front == MAX - 1) {
        front = 0;
    }
    else {
        front++;
    }
}
void pop_back() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted element: %d\n", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    }
    else if (rear == 0) {
        rear = MAX - 1;
    }
    else {
        rear--;
    }
}
void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}
void getFront() {
    if (isEmpty())
        printf("Deque is empty\n");
    else
        printf("Front element: %d\n", deque[front]);
}
void getBack() {
    if (isEmpty())
        printf("Deque is empty\n");
    else
        printf("Rear element: %d\n", deque[rear]);
}
void size() {
    if (isEmpty()) {
        printf("Size: 0\n");
        return;
    }
    if (rear >= front)
        printf("Size: %d\n", rear - front + 1);
    else
        printf("Size: %d\n", MAX - front + rear + 1);
}
int main() {
    int choice, value;
    while (1) {
        printf("\nDeque Operations\n");
        printf("1. Push Front\n");
        printf("2. Push Back\n");
        printf("3. Pop Front\n");
        printf("4. Pop Back\n");
        printf("5. Front\n");
        printf("6. Back\n");
        printf("7. Size\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            push_front(value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            push_back(value);
            break;
        case 3:
            pop_front();
            break;
        case 4:
            pop_back();
            break;
        case 5:
            getFront();
            break;
        case 6:
            getBack();
            break;
        case 7:
            size();
            break;
        case 8:
            display();
            break;
        case 9:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}

/*Output
Deque Operations
1. Push Front
2. Push Back
3. Pop Front
4. Pop Back
5. Front
6. Back
7. Size
8. Display
9. Exit
Enter choice: 2
Enter value: 10

Deque Operations
1. Push Front
2. Push Back
3. Pop Front
4. Pop Back
5. Front
6. Back
7. Size
8. Display
9. Exit
Enter choice: 2
Enter value: 20

Deque Operations
1. Push Front
2. Push Back
3. Pop Front
4. Pop Back
5. Front
6. Back
7. Size
8. Display
9. Exit
Enter choice: 1
Enter value: 5

Deque Operations
1. Push Front
2. Push Back
3. Pop Front
4. Pop Back
5. Front
6. Back
7. Size
8. Display
9. Exit
Enter choice: 8
Deque elements: 5 10 20 
*/