//Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* top = NULL;
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = top;
    int value = temp->data;
    top = top->next;
    free(temp);
    return value;
}
int evaluatePostfix(char exp[]) {
    int i = 0;
    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        }
        else {
            int val2 = pop();
            int val1 = pop();
            switch (exp[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
        i++;
    }
    return pop();
}
int main() {
    char exp[100];
    printf("Enter Postfix Expression: ");
    scanf("%s", exp);
    int result = evaluatePostfix(exp);
    printf("Result = %d\n", result);
    return 0;
}

/*Output
Enter Postfix Expression: 23*54/7
Result = 7
*/