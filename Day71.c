//Problem Statement Implement a hash table using quadratic probing with formula:
//h(k, i) = (h(k) + i*i) % m

#include <stdio.h>
#include <string.h>
#define EMPTY -1
int table[100];
void insert(int key, int m) {
    int index = key % m;
    for (int i = 0; i < m; i++) {
        int newIndex = (index + i * i) % m;
        if (table[newIndex] == EMPTY) {
            table[newIndex] = key;
            return;
        }
    }
    printf("Hash Table Overflow\n");
}
void search(int key, int m) {
    int index = key % m;
    for (int i = 0; i < m; i++) {
        int newIndex = (index + i * i) % m;
        if (table[newIndex] == key) {
            printf("FOUND\n");
            return;
        }
        if (table[newIndex] == EMPTY) {
            break;
        }
    }
    printf("NOT FOUND\n");
}
int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }
    char operation[10];
    int key;
    for (int i = 0; i < q; i++) {
        scanf("%s %d", operation, &key);
        if (strcmp(operation, "INSERT") == 0) {
            insert(key, m);
        } else if (strcmp(operation, "SEARCH") == 0) {
            search(key, m);
        }
    }
    return 0;
}