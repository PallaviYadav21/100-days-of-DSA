//Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};
struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}
struct Node* insertTerm(struct Node* head, int c, int e) {
    struct Node* newNode = createNode(c, e);
    if (head == NULL)
        return newNode;
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}
void display(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    struct Node* poly = NULL;
    int n, coeff, exp;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        poly = insertTerm(poly, coeff, exp);
    }
    printf("Polynomial: ");
    display(poly);
    return 0;
}

/*Output
Enter number of terms: 5
Enter coefficient and exponent: 10 1
Enter coefficient and exponent: 20 2
Enter coefficient and exponent: 30 3
Enter coefficient and exponent: 40 4
Enter coefficient and exponent: 50 5
Polynomial: 10x^1 + 20x^2 + 30x^3 + 40x^4 + 50x^5
*/