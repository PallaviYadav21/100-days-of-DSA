//Implement push and pop operations on a stack and verify stack operations.

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
        top--;
    }
}
int main() {
    int n, m;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        push(value);
    }
    printf("Enter number of pop operations: ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        pop();
    }
    printf("Remaining stack elements (top to bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    return 0;
}

/*Output
Enter number of elements: 5
Enter 5 elements:
10 20 30 40 50
Enter number of pop operations: 3
Remaining stack elements (top to bottom): 20 10 
*/