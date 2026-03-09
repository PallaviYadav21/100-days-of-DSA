//Implement a Priority Queue using an array. An element with smaller value has higher priority.

#include <stdio.h>
#define MAX 100
int pq[MAX];
int size = 0;
void insert(int x)
{
    if(size == MAX)
    {
        printf("Priority Queue Overflow\n");
        return;
    }
    pq[size] = x;
    size++;
    printf("Element inserted successfully\n");
}
void deleteElement()
{
    if(size == 0)
    {
        printf("Priority Queue Underflow\n");
        return;
    }
    int minIndex = 0;
    for(int i = 1; i < size; i++)
    {
        if(pq[i] < pq[minIndex])
            minIndex = i;
    }
    printf("Deleted element: %d\n", pq[minIndex]);
    for(int i = minIndex; i < size - 1; i++)
    {
        pq[i] = pq[i + 1];
    }
    size--;
}
void peek()
{
    if(size == 0)
    {
        printf("Priority Queue is Empty\n");
        return;
    }

    int min = pq[0];

    for(int i = 1; i < size; i++)
    {
        if(pq[i] < min)
            min = pq[i];
    }

    printf("Element with highest priority: %d\n", min);
}
void display()
{
    if(size == 0)
    {
        printf("Priority Queue is Empty\n");
        return;
    }
    printf("Priority Queue Elements: ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", pq[i]);
    }
    printf("\n");
}
int main()
{
    int choice, value;
    while(1)
    {
        printf("\nPriority Queue Operations\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                deleteElement();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

/*Output
Priority Queue Operations
1. Insert
2. Delete
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter value to insert: 10
Element inserted successfully

Priority Queue Operations
1. Insert
2. Delete
3. Peek
4. Display
5. Exit
Enter your choice: 1
Enter value to insert: 20
Element inserted successfully

Priority Queue Operations
1. Insert
2. Delete
3. Peek
4. Display
5. Exit
Enter your choice: 3
Element with highest priority: 10

Priority Queue Operations
1. Insert
2. Delete
3. Peek
4. Display
5. Exit
Enter your choice: 30
Invalid choice

Priority Queue Operations
1. Insert
2. Delete
3. Peek
4. Display
5. Exit
Enter your choice: 2
Deleted element: 10

Priority Queue Operations
1. Insert
2. Delete
3. Peek
4. Display
5. Exit
Enter your choice: 3
Element with highest priority: 20

Priority Queue Operations
1. Insert
2. Delete
3. Peek
4. Display
5. Exit
Enter your choice: 4
Priority Queue Elements: 20 

Priority Queue Operations
1. Insert
2. Delete
3. Peek
4. Display
5. Exit
Enter your choice: 5
*/