//Given a queue of integers, reverse the queue using a stack.

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int queue[MAX];
int stack[MAX];
int front = 0, rear = -1;
int top = -1;
void enqueue(int x) {
    queue[++rear] = x;
}
int dequeue() {
    return queue[front++];
}
void push(int x) {
    stack[++top] = x;
}
int pop() {
    return stack[top--];
}
int main() {
    int n, i, x;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter queue elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }
    for(i = 0; i < n; i++) {
        push(dequeue());
    }
    front = 0;
    rear = -1;
    for(i = 0; i < n; i++) {
        enqueue(pop());
    }
    printf("Reversed Queue:\n");
    for(i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    return 0;
}

/*Output
Enter number of elements: 5
Enter queue elements:
1 2 3 4 5
Reversed Queue:
5 4 3 2 1 
*/