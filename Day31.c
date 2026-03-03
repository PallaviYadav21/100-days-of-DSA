//Implement a stack data structure using an array with the following operations: push, pop, and display.

#include <stdio.h>
#define MAX 1000
int stack[MAX];
int top = -1;
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = value;
    }
}
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d\n", stack[top--]);
    }
}
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
int main() {
    int n;
    printf("Enter number of operations: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int type, value;
        printf("Enter operation (1 value for push, 2 for pop, 3 for display): ");
        scanf("%d", &type);
        if (type == 1) {
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
        }
        else if (type == 2) {
            pop();
        }
        else if (type == 3) {
            display();
        }
        else {
            printf("Invalid operation\n");
        }
    }
    return 0;
}

/*Output
Enter number of operations: 5
Enter operation (1 value for push, 2 for pop, 3 for display): 1
Enter value to push: 10
Enter operation (1 value for push, 2 for pop, 3 for display): 1
Enter value to push: 20
Enter operation (1 value for push, 2 for pop, 3 for display): 3
20 10 
Enter operation (1 value for push, 2 for pop, 3 for display): 2
20
Enter operation (1 value for push, 2 for pop, 3 for display): 3
10 
*/